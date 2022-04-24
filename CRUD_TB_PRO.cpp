#include "proveedores.cpp"
#include <mysql.h>
#include <iostream>
#include <iomanip>

int main()
{
    Proveedor obj = Proveedor(char chr_id[25], char chr_pro[60], char chr_nit[12], char chr_dir[80], char chr_tel[25]);
    ingreso();
    /*
    int int_fin = 0;
    do {
        int int_menu, int_op;
        banner_motd();
        cout << "Agregar ............................. 1" << endl;
        cout << "Mostrar ............................. 2" << endl;
        cout << "Actualizar .......................... 3" << endl;
        cout << "Eliminar ............................ 4" << endl;
        cout << "Salir ............................... 5" << endl;
        cout << "\n  Bienvenido, escoge una opcion:";
        cin >> int_menu;
        system("cls");
        switch (int_menu)
        {
        case 1:
            banner_motd();
            obj.ingreso();
            break;
        case 2:
            banner_motd();
            obj.mostrar();
            break;
        case 3:
            obj.update();
            break;
        case 4:
            obj.eliminar();
            break;
        case 5:
            int_fin = 1;
            cout << "Hora de salida ";
            system("time /t");
            break;
        default:
            cout << "Opcion no valida, sirvase a intentar de nuevo";
            break;
        }
    } while (int_fin == 0);

}
