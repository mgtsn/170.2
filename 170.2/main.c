#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "parser.h"
#include "lexer.h"
#include "cell.h"

int main(int argc, const char * argv[]) {
	
	List s;

	
	while (1)
	{
		//Infinitely read expressions from the user, analyze them, and print them out
		printf("scheme> ");
		s = S_Expression();
		printList(s);
	}
    return 0;
}
