#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "parser.h"
#include "lexer.h"

static char token [20];
static int ended = 0;
//Array of strings to hold each token in order; later converted to list
char c[100][20];
int count = 0;



//function for indenting output
static void Space(int n)
{
	while(n > 0)
	{
		printf("  ");
		n--;
	}
}

static void S_Helper(int depth)
{
	//Check for opening parentheses
	if(!strncmp(token, "(", 20))
	{
		//Space(depth);
		//printf("%s\n", "S_Expression");
		//Space(depth);
		//printf("%s\n", token);
		strcpy(c[count], token);
		count++;
		
		//search for a close parentheses, printing out stuff inbetween
		while(strncmp(token, ")", 20))
		{
			
			
			if (ended)
			{
				ended = 0;
			}
			else
			{
				strcpy(token, getToken());
				
			}
			//If it is not a close parentheses, recursively call the function at a greater depth
			S_Helper(depth + 1);
		}
		//Space(depth);
		//printf("%s\n", token);
		strcpy(c[count], token);
		count++;
		if (depth == 0)
		{
			return;
		}
		strcpy(token, getToken());
		ended = 1;
		
	}
	else
	{
		//Print out any expressions
		if (strncmp(token, ")", 20))
		{
			//Space(depth);
			//printf("%s\n", "S_Expression");
			//Space(depth + 1);
			//printf("%s\n", token);
			strcpy(c[count], token);
			count++;
		}
	}
}

//calls start token and gets the first token
//calls the helper function with depth 0
List S_Expression()
{
	count = 0;
	startTokens(20);
	strcpy(token, getToken());
	S_Helper(0);
	
	List l = createCell(c[0]);
	
	List last = l;
	
	//convert stored tokens to list
	int t = 1;
	while (t < count)
	{
		last->cdr = createCell(c[t]);
		last = last->cdr;
		t++;
	}
	return l;
}


void printList(List l)
{
	List temp = l;
	while(temp->cdr != NULL)
	{
		printf("%s", temp->car);
                if (*temp->car != '(' & *temp->cdr->car != ')')
		{
			printf("%s", " ");
		} 
		temp = temp->cdr;
		
	}
	printf("%s\n", temp->car);
}




