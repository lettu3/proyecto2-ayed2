#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static unsigned int partition(int a[], unsigned int izq, unsigned int der){
    unsigned int i, j, pivot;
    pivot = izq;
    i = izq + 1;
    j = der;
    while (i <= j){
        if (goes_before(a[i], a[pivot])){
            i = i + 1;
        }
        else if (goes_before(a[pivot], a[j])){
            j = j - 1;
        }
        else if (goes_before(a[j], a[pivot]) && goes_before(a[pivot], a[i])){
            swap(a, i, j);
        }
    }
    swap(a, pivot, j);
    pivot = j;

    return pivot;

}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der){
    unsigned int pivot;
    if (der > izq){
        pivot = partition(a, izq, der);
        quick_sort_rec(a, izq, (pivot == 0u) ? 0u : pivot - 1u);
        quick_sort_rec(a, pivot + 1u, der);
    }
}

void quick_sort(int a[], unsigned int length){
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}
