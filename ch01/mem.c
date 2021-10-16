#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int main(int argc, char *argv[])
{
    int *p = malloc(sizeof(int));                               // a1
    assert(p != NULL);                                          // terminate if p is null
    printf("(%d) address pointed to by p: %p\n", getpid(), p);  // a2
    *p =0; 
    int c = 0;                                                  // a3

    while(1) {
        Spin(1);
        *p = *p + 1;
        c += 1;
        printf("(%d) p: %d\n", getpid(), *p); 
        if ( c == 3 ){
            exit (100);
            // break;
        }                  // a4
    }
    return 0;
}