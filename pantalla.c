#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"

static int buscarLugarLibre(eEmpleado* array,int tam);
static int proximoId();

int empleado_init(eEmpleado* array,int tam)
{
    int retorno = -1;
    int i;
    if(tam > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0; i<tam; i++)
        {
            array[i].isEmpty = 0;
        }
    }
    return retorno;
}

static int buscarLugarLibre(eEmpleado* array,int tam)
{
    int retorno = -1;
    int i;
    if(tam > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0; i<tam; i++)
        {
            if(array[i].isEmpty == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int empleado_alta(eEmpleado* array,int tam)
{
    int retorno = -1;
    char name[50];
    char lastName[50];
    float salary;
    int sector;
    int isEmpty;
    int id;

    int indice = buscarLugarLibre(array,tam);

    if(tam > 0 && array != NULL)
    {
        retorno = -2;

        if(indice >= 0)
        {
            id = proximoId();
            retorno = -3;
            if(!getValidString("Name?","Dato ingresado erroneo\n","Overflow", name,50,2))
            {
                if(!getValidString("Last name?","Dato ingresado erroneo\n","Overflow", lastName,50,2))
                {
                    if(!getValidFloat("Salary?","Dato ingresado erroneo\n",&salary,0,200000,2))
                    {

                        if(!getValidInt("Sector?","Dato ingresado erroneo\n",&sector,0,999,2))
                        {
                            retorno = 0;

                            strcpy(array[indice].name,name);
                            strcpy(array[indice].lastName,lastName);
                            array[indice].sector=sector;
                            array[indice].salary=salary;

                            array[indice].id = id;
                            array[indice].isEmpty = 1;

                        }
                    }
                }
            }
        }
    }
    return retorno;
}

int empleado_modificacion(eEmpleado* array,int tam, int id)
{
    int retorno = -1;
    char name[50];
    char lastName[50];
    float salary;
    int sector;
    int isEmpty;
    int indice = empleado_buscarPorId(array,tam,id);

    if(indice >= 0)
    {
        retorno = -2;

        if(!getValidString("Name?","Dato ingresado erroneo\n","Overflow", name,50,2))
        {
            if(!getValidString("Last name?","Dato ingresado erroneo\n","Overflow", lastName,50,2))
            {
                if(!getValidFloat("Salary?","Dato ingresado erroneo\n",&salary,0,200000,2))
                {

                    if(!getValidInt("Sector?","Dato ingresado erroneo\n",&sector,0,999,2))
                    {
                        retorno = 0;

                        strcpy(array[indice].name,name);
                        strcpy(array[indice].lastName,lastName);
                        array[indice].sector=sector;
                        array[indice].salary=salary;
                    }
                }
            }
        }
        return retorno;
    }
}

int empleado_baja(eEmpleado* array,int tam, int id)
{

    int retorno = -1;
    int indice;
    indice = empleado_buscarPorId(array,tam,id);
    if(indice >= 0)
    {
        retorno = 0;
        array[indice].isEmpty = 0;
    }
    return retorno;
}

int empleado_mostrar(eEmpleado* array,int tam)
{
    int retorno = -1;
    int i;
    if(tam > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0; i<tam; i++)
        {
            if(array[i].isEmpty == 1)
            {
                printf("\n Nombre: %s  Apellido:%s  Salario: %2.f  Sector: %d Id: %d \n",array[i].name,array[i].lastName,array[i].salary, array[i].sector, array[i].id);
            }
        }
    }
    return retorno;

}

int empleado_ordenar(eEmpleado* array,int tam, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    eEmpleado auxiliar;

    if(tam > 0 && array != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0; i<tam-1; i++)
            {
                if(array[i].isEmpty == 1 && array[i+1].isEmpty == 1 )
                {
                    if((strcmp(array[i].name,array[i+1].name) > 0 && !orden) || (strcmp(array[i].name,array[i+1].name) < 0 && orden)) //<------------
                    {
                        auxiliar = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliar;
                        flagSwap = 1;
                    }
                }
            }
        }
        while(flagSwap);
    }

    return retorno;
}
int empleado_buscarPorId(eEmpleado* array,int tam, int id)
{
    int retorno = -1;
    int i;
    if(array > 0 && array != NULL)
    {
        retorno = -2;

        for(i=0; i<tam; i++)
        {

            if(array[i].isEmpty == 1 && array[i].id == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
static int proximoId()
{
    static int ultimoId = 0;
    ultimoId++;
    return ultimoId;
}
int calificacionempleado(eEmpleado* array, int tam)
{
    int retorno = -1;
    int i;
    float promedio;
    if(tam > 0 && array != NULL)
    {
        retorno = -1;
        for(i=0; i<tam; i++)
        {
            if(array[i].isEmpty == 1)
            {

                printf("\n Empleado : %s ", array[i].name);
                retorno = 0;

            }
        }
    }
    return retorno;

}
int empleado_informe(eEmpleado* array, int tam)
{
    int contadorEmpleados=0;
    float acumuladorSalario=0;
    int i;
    float promedio;
    int retorno = -1;
    int salarioSuperiorAlPromedio=0;

    if(tam > 0 && array != NULL)
    {

        for(i=0; i<tam; i++)
        {
            if(array[i].isEmpty == 1)
            {
                acumuladorSalario = acumuladorSalario + array[i].salary;
                contadorEmpleados++;
                retorno = 0;
            }
        }
        promedio= acumuladorSalario/contadorEmpleados;

        for(i=0; i<tam; i++)
        {
            if(array[i].isEmpty == 1)
            {
                if(array[i].salary > promedio)
                {
                    salarioSuperiorAlPromedio++;
                }
            }
        }
        printf("\n Cantidad de empleados: %d \n Total salario: %.2f \n Salario promedio: %.2f \n Empleados con salario mayor al promedio: %d \n",contadorEmpleados, acumuladorSalario,promedio,salarioSuperiorAlPromedio);
    }
    return retorno;
}
