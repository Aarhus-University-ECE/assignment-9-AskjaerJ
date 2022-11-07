#include "sum.h"

int sum(int a[], int n)
{
    if (n == 0) { /* if the array size is 0, no need to sum. */
        return 0;
    }
    else if (n > 0) { 
    return (sum(a, n - 1) + a[n - 1]); /* Recursive sum, calls function sum. */
    }
}