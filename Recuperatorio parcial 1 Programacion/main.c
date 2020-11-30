#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
}Notebook;


float aplicarIVA (float precio);
int reemplazarCaracter(char cadena[], char caracter1, char caracter2);
void ordenarNotebooks(Notebook vec[], int tam);


int main()
{

    float precio=100;

    char cadena[]="Hola como estas";
    char caracter1='o';
    char caracter2 = 'p';
    int contador;

    Notebook notebooks[]={{1, "core", "Hp", 7400.76}, {2, "core", "Hp", 5500.99}, {3, "core", "Samsung", 5000.87}, {4, "core", "Hitachi", 3003.00}};

// ---------------------------------------------------------
    printf("Precio: %.2f\n", precio);
    printf("IVA : %.2f\n\n", aplicarIVA(precio));

    puts(cadena);
    printf("\n");
    contador=reemplazarCaracter(cadena, caracter1, caracter2);
    puts(cadena);
    printf("\nEn la cadena, el caracter %c fue reemplazado %d veces\n\n", caracter1, contador);

    for(int i=0;i<4;i++)
    {
        printf("%s, %.2f\n", notebooks[i].marca, notebooks[i].precio);
    }
    printf("\n");

    ordenarNotebooks (notebooks, 4);

    for(int i=0;i<4;i++)
    {
        printf("%s, %.2f\n", notebooks[i].marca, notebooks[i].precio);
    }
    printf("\n");

    return 0;
}


float aplicarIVA (float precio)
{
    return precio * .21;
}

int reemplazarCaracter(char cadena[], char caracter1, char caracter2)
{
    int contador=0;

    for(int i=0;cadena[i]!='\0';i++)
    {
        if(cadena[i]==caracter1)
        {
            cadena[i]=caracter2;
            contador++;
        }
    }

    return contador;
}

void ordenarNotebooks(Notebook vec[], int tam)
{
    Notebook aux;
    for(int i=0; i < tam-1; i++)
    {
        for(int j=i+1 ;j < tam ;j++)
        {
            if(strcmp(vec[i].marca, vec[j].marca)>0)
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }

            else if(strcmp(vec[i].marca, vec[j].marca)==0)
            {
                if(vec[i].precio>vec[j].precio)
                {
                    aux=vec[i];
                    vec[i]=vec[j];
                    vec[j]=aux;
                }
            }
        }
    }
}
