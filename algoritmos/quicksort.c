#include <stdio.h>

#define UMBRAL 1

void ord_ins(int v[], int n)
{
    int i, x, j;

    for (i = 0; i < n; i++)
    {
        x = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > x)
        {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = x;
    }
}

int numaleatorio(int M, int N)
{
    return (rand() % (N - M + 1) + M);
}

void intercambiar(int *a, int *b)
{
    int temporal = *a;
    *a = *b;
    *b = temporal;
}

void rapida_aux(int v[], int izq, int der)
{
    int pivote, x, i, j;

    if ((izq + UMBRAL) <= der)
    {
        x = numaleatorio(izq, der);
        pivote = v[x];
        intercambiar(&v[izq], &v[x]);
        i = izq + 1;
        j = der;
        while (i <= j)
        {
            while (i <= der && v[i] < pivote)
                i = i + 1;
            while (v[j] > pivote)
                j = j - 1;
            if (i <= j)
            {
                intercambiar(&v[i], &v[j]);
                i = i + 1;
                j = j - 1;
            }
        }
        intercambiar(&v[izq], &v[j]);
        rapida_aux(v, izq, j - 1);
        rapida_aux(v, j + 1, der);
    }
}

void ord_rapida(int v[], int n)
{
    rapida_aux(v, 0, n - 1);
    if (UMBRAL > 1)
        ord_ins(v, n);
}