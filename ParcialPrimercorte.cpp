/*
INTENGRATES:
Daniel Steve Montaño arboleda
Faiber Pacheco Silva.
*/
#include <iostream>
#include <malloc.h>
using namespace std;
    struct producto
    {
        int ID;
        char Nombre_producto [40];
        int Cantidad_Producto;
        double Precio_u_producto;

        int num;

        double pretot;

        struct producto *sig;
    };

producto *cab, *fin, *aux, *aux2;   

int registrar(){
    if(cab==NULL)
    {
    cab=(struct producto *) malloc (sizeof(struct producto));

        cout<<"Ingres ID del producto: ";
        cin>> cab->ID;

        cout<<"Ingrese el nombre del producto: ";
        cin>> cab->Nombre_producto;

        cout<<"Ingrese la cantidad del producto: ";
        cin>> cab->Cantidad_Producto;

        cout<<"Ingrese el precio del producto: $";
        cin>> cab->Precio_u_producto;

        cout<<"\t Gracias por registrar un nuevo producto"<<endl;

        cab->sig = NULL;
        free(aux);
    }
    else
    {
        aux = (struct producto *)malloc(sizeof(struct producto));


        cout<<"ingres ID del producto: ";
        cin>> aux->ID;

        cout<<"ingrese el nombre del producto: ";
        cin>> aux->Nombre_producto;

        cout<<"ingrese la cantidad del producto: ";
        cin>> aux->Cantidad_Producto;

        cout<<"ingrese el precio del producto: $";
        cin>> aux->Precio_u_producto;

        cout<<"\t Gracias por registrar un nuevo producto: "<<endl;


        aux->sig = NULL;
        
        aux2 = cab;
        
        while (aux2->sig != NULL) 
        {aux2 = aux2->sig;}
        aux->num = aux2->num + 1;
        
        aux2->sig = aux;

        aux = NULL;

        aux2 = aux;

        free(aux);

        free(aux2);
    }

    return 0;
}

int mostrar(){
    
   for (aux = cab; aux != NULL; aux = aux->sig)
    {
        cout << "Producto #" << aux->num + 1 << endl;
        cout<< "ID del producto -> " << aux->ID << endl;;
        cout<< "Nombre del producto -> " << aux->Nombre_producto << endl;
        cout<< "Cantidad del producto -> " << aux->Cantidad_Producto << endl;
        cout<< "Precio del producto X und. -> $" << aux->Precio_u_producto << endl;
        cout<<"   "<<endl;
        cout<<"   "<<endl;
        
        
        
    }
    
   
    return 0;
}

int buscar() {
    int id_buscar;
    cout << "Ingrese el ID del producto que desea buscar: ";
    cin >> id_buscar;

    aux = cab;
    while (aux != NULL) {
        if (aux->ID == id_buscar) {
            cout << "Producto encontrado:" << endl;
            cout << "ID del producto -> " << aux->ID << endl;
            cout << "Nombre del producto -> " << aux->Nombre_producto << endl;
            cout << "Cantidad del producto -> " << aux->Cantidad_Producto << endl;
            cout << "Precio del producto X und. -> $" << aux->Precio_u_producto << endl;
            return 0;
        }
        aux = aux->sig;
    }

    cout << "No se encontró el producto con el ID ingresado." << endl;
    return 0;
}

int eliminar() {
    int id_eliminar;
    cout << "Ingrese el ID del producto que desea eliminar: ";
    cin >> id_eliminar;

    
    if (cab != NULL && cab->ID == id_eliminar) {
        aux = cab;
        cab = cab->sig;
        free(aux);
        cout << "Producto eliminado correctamente." << endl;
        return 0;
    }

   
    aux2 = cab;
    while (aux2->sig != NULL) {
        if (aux2->sig->ID == id_eliminar) {
            aux = aux2->sig;
            aux2->sig = aux->sig;
            free(aux);
            cout << "Producto eliminado correctamente." << endl;
            return 0;
        }
        aux2 = aux2->sig;
    }

    cout << "No se encontró el producto con el ID ingresado." << endl;
    return 0;
}

int Calcula_Valor_Total_Inventario(){
    double to;
    for (aux = cab; aux != NULL; aux = aux->sig)
    {
        aux->pretot = aux->Cantidad_Producto * aux->Precio_u_producto;
        to = to + aux->pretot;
        

    }
    cout<<"El precio total del inventario es -> $"<<to<<endl;

    return 0;
}

int Calcular_Promedio_Precios() {
    double suma_precios = 0.0;
    int cantidad_productos = 0;

    for (aux = cab; aux != NULL; aux = aux->sig) {
        suma_precios += aux->Precio_u_producto;
        cantidad_productos++;
    }

    if (cantidad_productos > 0) {
        double promedio = suma_precios / cantidad_productos;
        cout << "El promedio de precios de los productos es: $" << promedio << endl;
    } else {
        cout << "No hay productos registrados." << endl;
    }

    return 0;
}

int Vender_Productos(){
       int IDs;
        int unid;
        int rest;
        int pago;
            cout<<"Igrese el ID del producto que desea comprar: ";
            cin>> IDs;

     for (aux = cab; aux != NULL; aux = aux->sig)
        {
            if (aux->ID == IDs)
            {
            cout << "Producto #" << aux->num + 1 << endl;
            cout<< "ID del producto -> " << aux->ID << endl;;
            cout<< "Nombre del producto -> " << aux->Nombre_producto << endl;
            cout<< "Cantidad del producto -> " << aux->Cantidad_Producto << endl;
            cout<< "Precio del producto X und. -> $" << aux->Precio_u_producto << endl;
            cout<<"   "<<endl;
            cout<<"   "<<endl;

                cout<<"Cuantas unidades desea comprar: ";
                cin>> unid;
                cout<<"   "<<endl;
        
                if  (aux->Cantidad_Producto < unid)
                {
                cout<<"No hay suficientes unidades del producto..."<<endl;
                break;
                }   
                    else (aux->Cantidad_Producto >= unid);{
                        cout<<"Si existen las unidades deseadas"<<endl; 
                        rest=aux->Cantidad_Producto - unid;
                        aux->Cantidad_Producto=rest;    
                        cout<<"\t Has seleccionado un producto"<<endl ;
                        pago= aux->Precio_u_producto * unid;
                        cout<<"La cantidad a pagar es de: "<< pago <<endl;
                    }
            } else (aux->ID!=IDs);{
            cout<<"\tEl ID ingresado no pertenece a ningun producto registrado"<<endl;
            }
        }

    return 0;
}
void despedir(){
    cout<<"Muchas gracias por usar nuestros servicios querido usuario"<<endl;
    cout<<"\tHata luego"<<endl;
}
void defecto(){
    cout<<"\tQuerido usuario la opcion digitada no pertenece a ninguna funcion en nuestro software"<<endl;
}




int main()
{
    int opc;
    do
    { 
    cout<<"\tMENU"<<endl; 
    cout<<"1. Registrar producto. \n2. Mostar productos \n3. Buscar producto. \n4. Eliminar producto."<<endl; 
    cout<<"5. Calcular valor total de inventario. \n6. Calcular promedio de precios."<<endl; 
    cout<<"7. Vender productos. \n8. Salir."<<endl;
    cout<<"\t Digite su opcion "<<endl;
    cin>>opc;
   
    switch (opc)
    {
    case 1: registrar();
        break;

    case 2: mostrar();
        break;

    case 3: buscar();
        break;
    
    case 4: eliminar();
        break;
    
    case 5:Calcula_Valor_Total_Inventario();
        break;
    
    case 6:Calcular_Promedio_Precios();
        break;
    
    case 7:Vender_Productos();
        break;
    
    case 8:despedir();

    default: defecto();
       break;
    }
        
    } while (opc!=8);
    

    return 0;
}