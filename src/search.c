#include "search.h"
#include <stdbool.h>

bool search(int a[], int n, int x)
{ /* Search function to search through an array */
    if(n == 0) { /* If array size is 0 there is no value. */
        return false;
    }
    else if (n > 0 && a[n-1] == x){ /* Condition 1; checks if the first value is equal to x.*/
        return true; 
    }
    else if (n > 0 && a[n-1] != x){ /* If not true or false earlier then run through the array. */
        return search(a, n - 1, x);
    }
}