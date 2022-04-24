#include <mysql.h>
#include <iostream>
#include <iomanip>

using namespace std;
using namespace std;
MYSQL* conector;
int status = 0;

class Proveedor{
  private : char idProveedores[25], proveedor[60], nit[12], direccion[80], telefono[25];
  public :
  Cliente(){
  }
  Cliente (char chr_id[25], char chr_pro[60], char chr_nit[12], char chr_dir[80], char chr_tel[25]){ 
  for (int i=0; i<80; i++){
	if(i<25){
		idProveedores[i] = chr_id[i];
		telefono[i] = chr_tel[i];
	}

	if(i<60){
		proveedor[i] = chr_pro[i];
	}

	if(i<12){
		nit[i] = chr_nit[i];
	}

	if(i<80){
		direccion[i] = chr_dir[i];
	}
  }

  
  }
  



struct Proveedores {
    char idProveedores[25], proveedor[60], nit[12], direccion[80], telefono[25];
};

void conexion_open_sql() {
    conector = mysql_init(0);
    conector = mysql_real_connect(conector, "127.0.0.1", "lab_pro", "lab_pro", "proveedor", 3306, NULL, 0);
    status = 1;
}

void conexion_closed_sql() {
    mysql_close(conector);
    status = 0;
}

void revision_sql() {
    system("cls");
    if (status == 0) {
        conexion_open_sql();
    }
}


void ingreso() {
    revision_sql();
    Proveedores proveedores;
    cout << "******************************" << endl;
    cout << "****Ingreso de proveedores****" << endl;
    cout << "******************************\n" << endl;
    cout << "Ingrese un nuevo proveedor: " << endl;
    cout << "Nombre: ";
    cin >> proveedor;
    cout << "NIT: ";
    cin >> nit;
    cout << "Direccion: ";
    cin >> direccion;
    cout << "Telefono: ";
    cin >> telefono;
        
    string str_proveedor(proveedor);
    string str_nit(nit);
    string str_direccion(direccion);
    string str_telefono(telefono);
        

    string insert_dat = "insert into proveedores(proveedor, nit, direccion, telefono) values ('" + str_proveedor + "', " + str_nit + ", '" + str_direccion + "', '" + str_telefono + "')";
    const char* execute_insert = insert_dat.c_str();
    int q_estado = mysql_query(conector, execute_insert);
    if (!q_estado) {
        cout << "\n\nValor agregado a proveedores a las ";
        system("time /t");
    }
    else {
        cout << "\n\nIngreso F\n\n";
    }

    system("pause");
    system("cls");
    conexion_closed_sql();
}


void mostrar(int tab) {
    revision_sql();
    MYSQL_ROW fila;
    MYSQL_RES* result;
 
    string show_dat = "select * from proveedores";
    const char* execute_show = show_dat.c_str();
    int q_estado = mysql_query(conector, execute_show);
    if (!q_estado) {
        cout << "*****************************************************************************" << endl;
        cout << "***********************************PROVEEDORES*******************************" << endl;
        cout << "*****************************************************************************" << endl;
        cout << "No. | ID |     Nombre     |    NIT    |       Direccion      |   Telefono   |" << endl;
        cout << "----+----+----------------+-----------+----------------------+--------------+" << endl;
        int i = 1;
        result = mysql_store_result(conector);
        while (fila = mysql_fetch_row(result)) {
            cout << i << setw(5) << " | " << setw(2) << fila[0] << " | " << setw(10) << fila[1] << " | " << setw(7) << fila[2] << " | " << setw(16) << fila[3] << " | " << setw(12) << fila[4] << " | " << endl;
            i++;
        }
    }
    else {
        cout << "\n\nMostrar F\n\n";
    }
   
    system("pause");
    conexion_closed_sql();
}

void eliminar() {
    int int_tabla;
    string delete_dat, str_id;
    cout << "Cuidado, esta a punto de eliminar a un proveedor!" << endl;
    mostrar();
    cout << "\n\n\n\nIngrese el ID para eliminar: ";
    cin >> str_id;
    revision_sql();
    delete_dat = "delete from proveedores where idProveedores=" + str_id;
    const char* execute_delete = delete_dat.c_str();
    int q_estado = mysql_query(conector, execute_delete);
    if (!q_estado) {
        cout << "Eliminado con exito...!\n\n";
        mostrar();
    }
    else {
        cout << "\n\nError al eliminar efe\n\n";
    }
    system("pause");
    system("cls");
}

void update() {
    string update_dat, str_id, str_new, str_column;
    cout << "Cuidado, esta a punto de modificar los registros de un proveedor!" << endl;
    mostrar();
    cout << "\n\n\n\nIngrese el ID para alterar: ";
    cin >> str_id;
    cout << "Ingresa el campo a editar: ";
    cin >> str_column;
    cout << "Ingrese el nuevo valor: ";
    cin >> str_new;
    revision_sql();
    update_dat = "update proveedores set " + str_column + "='" + str_new + "' where idProveedores=" + str_id;
    const char* execute_update = update_dat.c_str();
    int q_estado = mysql_query(conector, execute_update);
    if (!q_estado) {
        cout << "\n\Valor actualizado a las ";
        system("time /t");
    }
    else {
        cout << "\n\nError, sirvase a intentar de nuevo\n\n";
    }
    system("pause");
    system("cls");
    conexion_closed_sql();
}

void banner_motd() {
    system("cls");
    system("date /t");
    cout << "\n\n   _|_|_|  _|_|_|    _|    _|  _|_|_|   " << endl;
    cout << " _|        _|    _|  _|    _|  _|    _| " << endl;
    cout << " _|        _|_|_|    _|    _|  _|    _|  " << endl;
    cout << " _|        _|    _|  _|    _|  _|    _| " << endl;
    cout << "   _|_|_|  _|    _|    _|_|    _|_|_|  \n" << endl;
}

};