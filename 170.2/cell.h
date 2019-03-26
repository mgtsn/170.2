
#ifndef cell_h
#define cell_h

#include <stdio.h>
#include "cell.h"

typedef struct cellstruct {
	struct cellstruct *car;
	struct cellstruct *cdr;
        char *data;
}*List;

List createCell(char *a);

#endif /* cell_h */
