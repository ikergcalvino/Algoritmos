#include <stdio.h>
#include <stdbool.h>

void ord_shell(int v[], int n)
{
    bool seguir;
    int i, j, tmp = 0;
    int incremento = n;

    do
    {
        incremento = incremento / 2;
        for (i = incremento; i < n; i++)
        {
            tmp = v[i];
            j = i;
            seguir = true;
            while ((j - incremento >= 0) && seguir)
            {
                if (tmp < v[j - incremento])
                {
                    v[j] = v[j - incremento];
                    j = j - incremento;
                }
                else
                    seguir = false;
            }
            v[j] = tmp;
        }
    } while (incremento > 1);
}