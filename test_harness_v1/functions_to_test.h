

/* *************************
 * 
 * In order to automatically test your program, you MUST implement the functions below.
 * The name of the function, the parameters it takes, and the return type has to be EXACTLY as specified below,
 * otherwise the test won't run.
 * 
 * For the purpose of testing rename your main() function into main_mine() and then compile the test as follows:
 * 
 * gcc --std=c99 -o test test.c unity.c YOURFILE.c
 * 
 * where you have substituted YOURFILE.c with the name of your file.
 * 
 * To run the tests, execute:  ./test
 * 
 * *************************
 */


#ifndef FUNCTIONS_TO_TEST_H__GUARD
#define FUNCTIONS_TO_TEST_H__GUARD


void stack_push(char c);

int stack_top(char *c);

int stack_pop(char *c);

char *remove_single_line_comment(const char *source);

char *remove_multi_line_comment(const char *source);

int parenthesis_match(const char *source);


#endif

