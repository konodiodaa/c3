
/* Author: Matteo Leonetti m.leonetti@leeds.ac.uk
 *
 * Contanct the instructors if this code does not compile, or for any other related problem.
 *
 *
 */


#include "functions_to_test.h"
#include "unity.h"
#include <stdlib.h>

void stack_rec ( int depth ) {

	if ( depth == 0 )
		return;

	char c = ( char ) rand() % 128;
	stack_push ( c );
	stack_rec ( depth-1 );

	char stack_c;

	stack_top ( &stack_c );
	TEST_ASSERT_EQUAL_UINT8_MESSAGE ( c,stack_c,"Stack top returned the wrong character" );

	stack_pop ( &stack_c );
	TEST_ASSERT_EQUAL_UINT8_MESSAGE ( c,stack_c,"Stack pop returned the wrong character" );
}



void test_stack() {

	char stack_c;

	TEST_ASSERT_TRUE_MESSAGE ( stack_top ( &stack_c ), "Top called on empty stack should return true" );
	TEST_ASSERT_TRUE_MESSAGE ( stack_pop ( &stack_c ), "Pop called on empty stack should return true" );

	for ( int i=1; i<= 200; ++i )
		stack_rec ( i );


	TEST_ASSERT_TRUE_MESSAGE ( stack_top ( &stack_c ), "Top called on empty stack should return true" );
	TEST_ASSERT_TRUE_MESSAGE ( stack_pop ( &stack_c ), "Pop called on empty stack should return true" );
}

void test_remove_single_line_comment()  {

	const int num_cases = 13;
	const char *cases[num_cases];
	cases[0] = "testing comments//  first";
	cases[1] = "testing comments  //  second";
	cases[2] = "testing comments//third";
	cases[3] = "testing comments//lots of stuff\n";
	cases[4] = "testing comments//lots of stuff\n\n";
	cases[5] = "testing comments \n//lots of stuff\n\n";
	cases[6] = "testing comments//lots of //stuff\n";
	cases[7] = "testing comments//lots of *stuff\n\n";
	cases[8] = "testing /comm*ents//lots of \n\n";
	cases[9] = "testing /comments//lots of stuff\n";
	cases[10] = "testing /comments//lots of */stuff\n";
	cases[11] = "testing // one line \n and // multiple line\n";
	cases[12] = "no comments really";

	const char *expected[num_cases];
	expected[0] = "testing comments";
	expected[1] = "testing comments  ";
	expected[2] = "testing comments";
	expected[3] = "testing comments\n";
	expected[4] = "testing comments\n\n";
	expected[5] = "testing comments \n\n\n";
	expected[6] = "testing comments\n";
	expected[7] = "testing comments\n\n";
	expected[8] = "testing /comm*ents\n\n";
	expected[9] = "testing /comments\n";
	expected[10] = "testing /comments\n";
	expected[11] = "testing \n and \n";
	expected[12] = "no comments really";

	for ( int i=0; i < num_cases; ++i ) {
			char *new_str = remove_single_line_comment ( cases[i] );

			TEST_ASSERT_EQUAL_STRING_MESSAGE ( expected[i],new_str, "Remove single line comment returned wrong string" );

			free ( new_str );
		}

}

void test_remove_multi_line_comment()  {

	const int num_cases = 9;
	const char *cases[num_cases];
	cases[0] = "testing comments*/  first";
	cases[1] = "testing /*comments  //  second\n*/";
	cases[2] = "testing /*comments*/";
	cases[3] = "testing comments/* \n lots\n of */stuff\n";
	cases[4] = "testing co/*mments//lots*/ of stuff\n*/\n";
	cases[5] = "testing /**/comments\n";
	cases[6] = "testing comm/*en*ts*/\n";
	cases[7] = "testing /*comments \n lots of /*stuff\n*/\n";
	cases[8] = "no comments really";

	const char *expected[num_cases];
	expected[0] = "testing comments*/  first";
	expected[1] = "testing ";
	expected[2] = "testing ";
	expected[3] = "testing commentsstuff\n";
	expected[4] = "testing co of stuff\n*/\n";
	expected[5] = "testing comments\n";
	expected[6] = "testing comm\n";
	expected[7] = "testing \n";
	expected[8] = "no comments really";

	for ( int i=0; i < num_cases; ++i ) {
			printf("%d",i);
			char *new_str = remove_multi_line_comment ( cases[i] );

			TEST_ASSERT_EQUAL_STRING_MESSAGE ( expected[i],new_str, "Remove multi-line comment returned wrong string" );

			free ( new_str );
		}

}

void setUp ( void ) {}

void tearDown ( void ) {}

int main ( void ) {
	UNITY_BEGIN();

	srand ( 1 ); //we all do the same tests.

	RUN_TEST ( test_stack );
	RUN_TEST ( test_remove_single_line_comment );
	RUN_TEST ( test_remove_multi_line_comment );

	return UNITY_END();
}
