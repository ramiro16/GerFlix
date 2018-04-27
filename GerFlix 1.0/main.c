#include <stdio.h>
#include <stdlib.h>
#include "Usuario.h"
#define TAMSERIE 20
#define TAMUSUARIO 100

void mostrarPersonaxSerie(eSerie[],int,eUsuario[],int);

int main()
{
    eSerie listaDeSeries[TAMSERIE];
    eUsuario listaDeUsuarios[TAMUSUARIO];

    inicializarSeriesEstado(listaDeSeries, TAMSERIE);
    inicializarSeriesHardCode(listaDeSeries);

    inicializarUsuariosEstado(listaDeUsuarios,TAMUSUARIO);
    inicializarUsuariosHardCode(listaDeUsuarios);

/*  1. Mostrar el listado de series TOLIS
    2. Mostrar el listado de usuarios TOLIS
    3. Mostrar el listado de Usuarios con el nombre de la serie que ve TOLIS
    4. Mostrar por cada serie, el nombre de los usuarios que la ven.
*/

    mostrarListaSeries(listaDeSeries, TAMSERIE);
    system("pause");
    system("cls");
    mostrarListaUsuarios(listaDeUsuarios, TAMUSUARIO);
    system("pause");
    system("cls");
    mostrarUsuarioConSuSerie(listaDeUsuarios,TAMUSUARIO,listaDeSeries,TAMSERIE);
    system("pause");
    system("cls");
    mostrarPersonaxSerie(listaDeSeries,TAMSERIE,listaDeUsuarios,TAMUSUARIO);


    return 0;
}


void mostrarListaSeries(eSerie listaDeSeries[],int tam)
{
    int i;

    printf("ID\tNOMBRE\tGENERO\t\tTEMPORADAS\n\n");

    for(i=0;i<tam;i++)
    {
        if(listaDeSeries[i].estado == 1)
        {
            printf("%d\t%s\t%-10s%10d\n",listaDeSeries[i].idSerie,listaDeSeries[i].nombre,listaDeSeries[i].genero, listaDeSeries[i].cantidadTemporadas);
        }
    }

}

void mostrarListaUsuarios(eUsuario listaDeUsuarios[], int tam)
{
    int i;

    printf("ID\t\tNOMBRE DE USUARIO\n\n");

    for(i=0;i<tam;i++)
    {
        if(listaDeUsuarios[i].estado == 1)
        {
            printf("%d\t\t%s\n",listaDeUsuarios[i].idUsuario,listaDeUsuarios[i].nombre);
        }
    }
}

void mostrarUsuarioConSuSerie(eUsuario listaDeUsuario[],int tamU, eSerie listaDeSerie[], int tamS)
{
    int i,j;

    printf("NOMBRE USUARIO\t\tSERIE QUE VE\n\n");

    for(i=0;i<tamU;i++)
    {
        for(j=0;j<tamS;j++)
        {
            if(listaDeUsuario[i].idSerie == listaDeSerie[j].idSerie && listaDeSerie[j].estado == 1 && listaDeUsuario[i].estado == 1)
            {
                printf("%-10s\t\t%10s\n",listaDeUsuario[i].nombre,listaDeSerie[j].nombre);
                break;
            }
        }
    }
}

void mostrarPersonaxSerie(eSerie series[],int tamS,eUsuario usuarios[],int tamU)
{
    int i,j;

    for(i=0;i<tamS;i++)
    {
        if(series[i].estado == 1)
        {
            printf("%Personas que miran %s\n",series[i].nombre);

            for(j=0;j<tamU;j++)
            {
                if(series[i].idSerie == usuarios[j].idSerie)
                {
                    printf("%s\n",usuarios[j].nombre);
                }

            }
        }
    }
}
