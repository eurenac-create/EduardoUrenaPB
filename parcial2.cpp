#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Usuario {
    int id;
    string nombre;
    string tipoCuenta;
    double saldo;
};

struct Transaccion {
    int idUsuario;
    double monto;
    string tipo;
};

int main() {
    vector<Usuario> usuarios;
    int n;

    // =========================
    // EJERCICIO 1
    // =========================
    cout << "Cuantos usuarios desea registrar: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Usuario u;

        cout << "\nUsuario " << i + 1 << endl;
        cout << "ID: ";
        cin >> u.id;

        cin.ignore();
        cout << "Nombre: ";
        getline(cin, u.nombre);

        cout << "Tipo de cuenta (debito/credito): ";
        getline(cin, u.tipoCuenta);

        cout << "Saldo: ";
        cin >> u.saldo;

        usuarios.push_back(u);
    }

    // Guardar en usuarios.txt
    ofstream archivoUsuarios("usuarios.txt");
    for (int i = 0; i < usuarios.size(); i++) {
        archivoUsuarios << usuarios[i].id << " "
                        << usuarios[i].nombre << " "
                        << usuarios[i].tipoCuenta << " "
                        << usuarios[i].saldo << endl;
    }
    archivoUsuarios.close();

    cout << "\nUsuarios guardados en archivo.\n";

    // Leer usuarios.txt
    ifstream leerUsuarios("usuarios.txt");
    Usuario temp;

    cout << "\nUsuarios registrados:\n";
    while (leerUsuarios >> temp.id >> temp.nombre >> temp.tipoCuenta >> temp.saldo) {
        cout << "ID: " << temp.id
             << " | Nombre: " << temp.nombre
             << " | Cuenta: " << temp.tipoCuenta
             << " | Saldo: " << temp.saldo << endl;
    }
    leerUsuarios.close();

    // =========================
    // EJERCICIO 2
    // =========================

    int m;
    cout << "\nCuantas transacciones desea ingresar: ";
    cin >> m;

    vector<Transaccion> transacciones;

    for (int i = 0; i < m; i++) {
        Transaccion t;

        cout << "\nTransaccion " << i + 1 << endl;
        cout << "ID Usuario: ";
        cin >> t.idUsuario;

        cout << "Monto: ";
        cin >> t.monto;

        cout << "Tipo (deposito/retiro): ";
        cin >> t.tipo;

        transacciones.push_back(t);
    }

    // Guardar transacciones.txt
    ofstream archivoTrans("transacciones.txt");
    for (int i = 0; i < transacciones.size(); i++) {
        archivoTrans << transacciones[i].idUsuario << " "
                     << transacciones[i].monto << " "
                     << transacciones[i].tipo << endl;
    }
    archivoTrans.close();

    // Aplicar transacciones
    for (int i = 0; i < transacciones.size(); i++) {
        for (int j = 0; j < usuarios.size(); j++) {
            if (usuarios[j].id == transacciones[i].idUsuario) {
                if (transacciones[i].tipo == "deposito") {
                    usuarios[j].saldo += transacciones[i].monto;
                } else if (transacciones[i].tipo == "retiro") {
                    usuarios[j].saldo -= transacciones[i].monto;
                }
            }
        }
    }

    // Guardar usuarios_actualizados.txt
    ofstream actualizados("usuarios_actualizados.txt");
    for (int i = 0; i < usuarios.size(); i++) {
        actualizados << usuarios[i].id << " "
                     << usuarios[i].nombre << " "
                     << usuarios[i].tipoCuenta << " "
                     << usuarios[i].saldo << endl;
    }
    actualizados.close();

    cout << "\nSaldos actualizados:\n";
    for (int i = 0; i < usuarios.size(); i++) {
        cout << "ID: " << usuarios[i].id
             << " | Nombre: " << usuarios[i].nombre
             << " | Saldo final: " << usuarios[i].saldo << endl;
    }

    return 0;
}
