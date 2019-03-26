#include <stdlib.h>
#include "cell.h"

List createCell(char *a)
{
	List c = malloc(sizeof(c));
	//struct cellstruct *d = malloc(sizeof(d));
	c->data = a;
        c->car = NULL;
	c->cdr = NULL;
	return c;
}
