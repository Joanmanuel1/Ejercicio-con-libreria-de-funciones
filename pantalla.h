
#define EUSUARIO_H_INCLUDED

typedef struct
{
    int id;
    char name[50];
    char lastName[50];
    float salary;
    int sector;
    int isEmpty;
}eEmpleado;

int empleado_init(eEmpleado* array,int tam);
int empleado_mostrar(eEmpleado* array,int tam);
int empleado_modificacion(eEmpleado* array, int tam, int id);
int empleado_alta(eEmpleado* array,int tam);
int empleado_baja(eEmpleado *array,int tam,int id);
int empleado_buscarPorId(eEmpleado* array,int tam, int id);
int empleado_ordenar(eEmpleado* array,int tam, int orden);
int empleado_informe(eEmpleado* array,int tam);
