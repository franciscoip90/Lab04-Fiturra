#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct Info {
   int num;
   struct Info *der;
   struct Info *izq;
} Info;

typedef Info *pNodo;
typedef Info *tree;


void insertar(tree *a, int dat);
int BUSCAR(tree a, int dat);
int Vacio(tree r);
int esHoja(pNodo r);
int numNodos(tree a, int* c);
int Alturatree(tree a, int* altura);
int alturaX(tree a, int dat);
void InOrden(tree, void (*func)(int*));
void PreOrden(tree, void (*func)(int*));
void PostOrden(tree, void (*func)(int*));

void auxcontador(tree a, int*);
void auxaltura(tree a, int, int*);

void Mostrar(int *d);

int main()
{
   tree treeInt=NULL;
   int altura, nnodos, i, dat;
   for(i=0; i<=6; i++){
    printf("ingrese valor del nodo numero %d: ", i);
    scanf("%i", &dat);
    printf("\n");
    insertar(&treeInt, dat);
   }
printf("Altura de arbol %d\n", Alturatree(treeInt, &altura));

   printf("InOrden: ");
   InOrden(treeInt, Mostrar);
   printf("\n");
   printf("PreOrden: ");
   PreOrden(treeInt, Mostrar);
   printf("\n");
   printf("PostOrden: ");
   PostOrden(treeInt, Mostrar);
   printf("\n");


   printf("numero de nodos hoja= %d\n", numNodos(treeInt, &nnodos));

   int nejem1,nejem2;


   nejem1=3;
   nejem2=4;


   printf("alto de %d = %d\n", nejem1,alturaX(treeInt, nejem1));

   printf("alto de %d= %d\n", nejem2, alturaX(treeInt, nejem2));

   printf("el peso del arbol es = %d\n", Alturatree(treeInt, &altura));


int numerobuscado=123;

    if(BUSCAR(treeInt,numerobuscado)){
        printf("el numero %d si esta \n",numerobuscado);
    }else{
        printf("el numero %d no esta \n",numerobuscado);

    }
if(Vacio(treeInt)==NULL){
    printf("el arbol no esta vacio \n");
}else{
       printf("el arbol esta vacio \n");

    }





   system("PAUSE");
   return 0;
}


void insertar(tree *a, int dat)
{
   pNodo padre = NULL;
   pNodo actual = *a;

   while(!Vacio(actual) && dat != actual->num) {
      padre = actual;
      if(dat < actual->num) actual = actual->izq;
      else if(dat > actual->num) actual = actual->der;
   }

   if(!Vacio(actual)) return;

   if(Vacio(padre)) {
      *a = (tree)malloc(sizeof(Info));
      (*a)->num = dat;
      (*a)->izq = (*a)->der = NULL;
   }

   else if(dat < padre->num) {
      actual = (tree)malloc(sizeof(Info));
      padre->izq = actual;
      actual->num = dat;
      actual->izq = actual->der = NULL;
   }

   else if(dat > padre->num) {
      actual = (tree)malloc(sizeof(Info));
      padre->der = actual;
      actual->num = dat;
      actual->izq = actual->der = NULL;
  }
}



void InOrden(tree a, void (*func)(int*))
{
   if(a->izq) InOrden(a->izq, func);
   func(&(a->num));
   if(a->der) InOrden(a->der, func);
}


void PreOrden(tree a, void (*func)(int*))
{
   func(&a->num);
   if(a->izq) PreOrden(a->izq, func);
   if(a->der) PreOrden(a->der, func);
}


void PostOrden(tree a, void (*func)(int*))
{
   if(a->izq) PostOrden(a->izq, func);
   if(a->der) PostOrden(a->der, func);
   func(&a->num);
}

int BUSCAR(tree a, int dat)
{
   pNodo actual = a;

   while(!Vacio(actual)) {
      if(dat == actual->num){
        return TRUE;  //LO ENCONTRO
      }


      else if(dat < actual->num) actual = actual->izq;
      else if(dat > actual->num) actual = actual->der;
   }
   return FALSE;//NO LO ENCONTRO


}

int alturaX(tree a, int dat)
{
   int altura = 0;
   pNodo actual = a;

   while(!Vacio(actual)) {
      if(dat == actual->num) return altura;
      else {
         altura++;
         if(dat < actual->num) actual = actual->izq;
         else if(dat > actual->num) actual = actual->der;
      }
   }
   return -1;
}

int numNodos(tree a, int *contador)
{
   *contador = 0;

   auxcontador(a, contador);
   return *contador;
}

void auxcontador(tree nodo, int *c)
{
   (*c)++;
   if(nodo->izq) auxcontador(nodo->izq, c);
   if(nodo->der)   auxcontador(nodo->der, c);
}

int Alturatree(tree a, int *altura)
{
   *altura = 0;

   auxaltura(a, 0, altura);
   return *altura;
}


void auxaltura(pNodo nodo, int a, int *altura)
{
   if(nodo->izq) auxaltura(nodo->izq, a+1, altura);
   if(nodo->der)   auxaltura(nodo->der, a+1, altura);

   if(esHoja(nodo) && a > *altura) *altura = a;
}

int Vacio(tree r)
{
   return r==NULL;
}

int esHoja(pNodo r)
{
   return !r->der && !r->izq;
}

void Mostrar(int *d)
{
   printf("%d, ", *d);
}

