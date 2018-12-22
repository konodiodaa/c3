
/* This is a template with the functions you must implement for this assignment.
 *
 * Note that you are free to implement any additional function you consider appropriate.
 *
 */
#include <stdlib.h>
#include <stdio.h>
#define SIZE 300
char stack[SIZE];
int sp=-1;


// push a character into the stack
void stack_push(char c){
	sp++;
	stack[sp]=c;
}

/* Overwrites the character pointed by c with the character currently on
 * top of the stack.
 *
 * The function returns 0 if the operation can be carried out successfully,
 * and any non-zero number if the operation could not be performed (for instance
 * because the stack is empty).
 */
int stack_top(char *c){
	if(sp!=-1 && sp<SIZE-1)
	{
		*c=stack[sp];
		return 0;
	}
	else
	{
		return 1;
	}
}

/* Overwrites the character pointed by c with the character currently on
 * top of the stack, and removes the character from the top of the stack.
 *
 * The function returns 0 if the operation can be carried out successfully,
 * and any non-zero number if the operation could not be performed (for instance
 * because the stack is empty).
 */
int stack_pop(char *c){
	if(sp!=-1)
	{
		*c=stack[sp];
		stack[sp]='\0';
		sp--;
		return 0;
	}
	else
	{
		return 1;
	}
}

/* Returns a dynamically allocated string (in the heap)
 * containing the characters in the string pointed by source,
 * excluding any one-line comment.
 */
char *remove_single_line_comment(const char *source){
	int i=0;
	int j=0;
	int n;
	char * newstring;

	n=100;
	newstring=(char *)malloc(n*sizeof(char));
	while(*(source+i)!='\0')
	{
			if(*(source+i)=='/' && *(source+i+1)=='/')
			{
				while(*(source+i)!='\0' && *(source+i)!='\n')
				{
					i++;
				}
				*(newstring+j)=*(source+i);
			}
			else
			{
				*(newstring+j)=*(source+i);
			}
			i++;
			j++;
	}
	*(newstring+j)='\0';
	return newstring;
}

/* Returns a dynamically allocated string (in the heap)
 * containing the characters in the string pointed by source,
 * excluding any multi-line comment.
 */
char *remove_multi_line_comment(const char *source){
	char *newstring;
	int n;
	int i;
	int j;

	n=100;
	i=0;
	j=0;
	newstring=(char *)malloc(n*sizeof(char));
	while(*(source+i)!='\0')
	{
		if(*(source+i)=='/' && *(source+i+1)=='*')
		{
			while((*(source+i)!='*' || *(source+i+1)!='/'))
			{
				i++;
			}
			i+=2;
			*(newstring+j)=*(source+i);
		}
		else
		{
			*(newstring+j)=*(source+i);
		}
		i++;
		j++;
	}
	*(newstring+j)='\0';
	return newstring;
}

/* The main function of your program. Rename into mymain
 * for testing.
 */

void

int main(int argc, char **argv) {

	//the code of your main function goes here.
	char source[SIZE]="testing comments//lots of stuff\n";
	char *newstring;

	newstring=remove_single_line_comment(source);

	printf("%s\n",newstring);
	free(newstring);
	return 0;
}
