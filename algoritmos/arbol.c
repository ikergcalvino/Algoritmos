#include <stdio.h>

struct nodo
{
    int elem;
    int num_repeticiones;
    struct nodo *izq, *der;
};

typedef struct nodo *posicion;
typedef struct nodo *arbol;

static struct nodo *crearnodo(int e)
{
    struct nodo *p = malloc(sizeof(struct nodo));
    if (p == NULL)
    {
        printf("memoria agotada\n");
        exit(EXIT_FAILURE);
    }
    p->elem = e;
    p->num_repeticiones = 1;
    p->izq = NULL;
    p->der = NULL;
    return p;
}

arbol insertar(int e, arbol a)
{
    if (a == NULL)
        return crearnodo(e);
    else if (e < a->elem)
        a->izq = insertar(e, a->izq);
    else if (e > a->elem)
        a->der = insertar(e, a->der);
    else
        a->num_repeticiones++;
    return a;
}

arbol creararbol()
{
    return NULL;
}

int esarbolvacio(arbol a)
{
    if (a == NULL)
        return 1;
    else
        return 0;
}

posicion hijoizquierdo(arbol a)
{
    return a->izq;
}

posicion hijoderecho(arbol a)
{
    return a->der;
}

int elemento(posicion p)
{
    return p->elem;
}

int numerorepeticiones(posicion p)
{
    return p->num_repeticiones;
}

posicion buscar(int i, arbol a)
{
    if (a == NULL)
        return NULL;
    else if (i == elemento(a))
        return a;
    else if (i < elemento(a))
        return buscar(i, hijoizquierdo(a));
    else if (i > elemento(a))
        return buscar(i, hijoderecho(a));
    else
        return NULL;
}

arbol eliminararbol(arbol a)
{
    if (a != NULL)
    {
        a->izq = eliminararbol(hijoizquierdo(a));
        a->der = eliminararbol(hijoderecho(a));
        free(a);
    }
    return NULL;
}

int altura(arbol a)
{
    int alt = 0, altizq = 0, altder = 0;

    if (esarbolvacio(a))
        return -1;
    else if (esarbolvacio(hijoizquierdo(a)) && esarbolvacio(hijoderecho(a)))
        return 0;
    else
    {
        if (!esarbolvacio(hijoizquierdo(a)))
            altizq += altura(hijoizquierdo(a));
        if (!esarbolvacio(hijoderecho(a)))
            altder += altura(hijoderecho(a));
        if (altizq >= altder)
            alt = altizq;
        else
            alt = altder;
        return ++alt;
    }
}

void visualizar(arbol a)
{
    if (esarbolvacio(a))
        printf("()");
    else
    {
        if (!esarbolvacio(hijoizquierdo(a)))
        {
            printf("(");
            visualizar(hijoizquierdo(a));
            printf(")");
        }
        printf(" %d ", elemento(a));
        if (!esarbolvacio(hijoderecho(a)))
        {
            printf("(");
            visualizar(hijoderecho(a));
            printf(")");
        }
    }
}