//MARCUS EMMANUEL - 514067//
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"


HEAP* HEAP_create(int n, COMP* comparacao) 
{
 HEAP* heap = malloc(sizeof(HEAP));
 heap->N = n;
 heap->P = 0;
 heap->elems = malloc(n * sizeof(void*));
 heap->comparador = comparacao;
 return heap;
}
//ADICIONA//
void HEAP_add(HEAP* heap, void* elem) 
{
    if(heap->P == heap->N) 
    {
        printf("Heap está cheio!!!\n");
        return;
    }
 
    heap->elems[heap->P] = elem;
    heap->P++;
    int add = heap->P - 1;

    while (add != 0 && heap->comparador(heap->elems[add], heap->elems[(add - 1) / 2]) == 
-1) 
    {
        void* auxi1 = heap->elems[add];
        heap->elems[add] = heap->elems[(add - 1) / 2];
        heap->elems[(add - 1) / 2] = auxi1;
        add = (add - 1) / 2;
    }
}
//REMOVE//
void* HEAP_remove(HEAP* heap) {
 if (heap->P <= 0) 
 {
    printf("Heap vazio!");
    return NULL;
 }
 int local = heap->P / 2;
 void* minimum = heap->elems[local];
 for (int add = local + 1; add < heap->P; add++) 
 {
    if (heap->comparador(heap->elems[add], minimum) > 0) 
    {
        minimum = heap->elems[add];
        local = add;
    }
 }

void* auxiliar = heap->elems[heap->P - 1];
heap->elems[heap->P] = heap->elems[local];
heap->elems[local] = auxiliar;

while (heap->comparador(heap->elems[local], heap->elems[(local - 1 / 2)]) < 0) 
{
    void* newAux = heap->elems[local];
    heap->elems[local] = heap->elems[(local - 1) / 2];
    heap->elems[(local - 1) / 2] = newAux;
    local = (local - 1) / 2;
}
heap->P--;
return minimum;
}
