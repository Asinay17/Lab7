#include <iostream>
#include <string>

using namespace std;
//holaaa
class CuentaBancaria {
private:
    string titular;
    double saldo;
    bool activa;
    bool bloqueada;
    int intentosFallidos;

public:
    CuentaBancaria(string nombre, double saldoInicial) {
        titular = nombre;
        saldo = saldoInicial;
        activa = saldoInicial > 0;
        bloqueada = false;
        intentosFallidos = 0;
    }

    void depositar(double monto) {
        if (bloqueada) {
            cout << "Cuenta bloqueada. No se pueden hacer depósitos.\n";
            return;
        }
        if (!activa) {
            cout << "No se puede depositar en una cuenta inactiva.\n";
            return;
        }
        if (monto > 0) {
            saldo += monto;
            cout << "Depósito exitoso. Nuevo saldo: $" << saldo << endl;
        }
        else {
            cout << "Monto inválido.\n";
        }
    }

    void retirar(double monto) {
        if (bloqueada) {
            cout << "Cuenta bloqueada. No se pueden hacer retiros.\n";
            return;
        }
        if (monto <= 0) {
            cout << "Monto inválido.\n";
            return;
        }
        if (saldo >= monto) {
            saldo -= monto;
            intentosFallidos = 0;
            cout << "Retiro exitoso. Nuevo saldo: $" << saldo << endl;
            if (saldo < 50) {
                cout << "ADVERTENCIA: Su saldo es bajo.\n";
            }
        }
        else {
            cout << "Saldo insuficiente.\n";
            intentosFallidos++;
            if (intentosFallidos >= 3) {
                bloqueada = true;
                cout << "Cuenta bloqueada por demasiados intentos fallidos.\n";
            }
        }
    }

    void transferir(CuentaBancaria& destino, double monto) {
        if (bloqueada) {
            cout << "No se puede transferir desde una cuenta bloqueada.\n";
            return;
        }
        if (destino.bloqueada) {
            cout << "No se puede transferir a una cuenta bloqueada.\n";
            return;
        }
        if (saldo >= monto && monto > 0) {
            saldo -= monto;
            destino.depositar(monto);
            cout << "Transferencia de $" << monto << " a " << destino.getTitular() << " realizada.\n";
        }
        else {
            cout << "Fondos insuficientes para la transferencia.\n";
        }
    }

    void mostrarSaldo() {
        cout << "Titular: " << titular << " | Saldo: $" << saldo << " | ";
        cout << (bloqueada ? "Cuenta BLOQUEADA" : "Cuenta ACTIVA") << endl;
    }

    string getTitular() {
        return titular;
    }
};


//hola

// Crear cuentas
CuentaBancaria cuenta1("Juan Perez", 500);
CuentaBancaria cuenta2("Maria Lopez", 1200);
CuentaBancaria cuenta3("Carlos Sánchez", 300);

// Función para seleccionar la cuenta
CuentaBancaria* seleccionarCuenta(int id) {
    switch (id) {
    case 1: return &cuenta1;
    case 2: return &cuenta2;
    case 3: return &cuenta3;
    default: return nullptr;
    }
}

void menu() {
    int opcion;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Depositar dinero\n";
        cout << "2. Retirar dinero\n";
        cout << "3. Transferir dinero\n";
        cout << "4. Ver saldo\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        int idCuenta, idDestino;
        double monto;
        CuentaBancaria* cuenta;
        CuentaBancaria* destino;

        switch (opcion) {
        case 1:
            cout << "Seleccione cuenta (1-3): ";
            cin >> idCuenta;
            cuenta = seleccionarCuenta(idCuenta);
            if (cuenta) {
                cout << "Ingrese monto a depositar: ";
                cin >> monto;
                cuenta->depositar(monto);
            }
            else {
                cout << "Cuenta inválida.\n";
            }
            break;

        case 2:
            cout << "Seleccione cuenta (1-3): ";
            cin >> idCuenta;
            cuenta = seleccionarCuenta(idCuenta);
            if (cuenta) {
                cout << "Ingrese monto a retirar: ";
                cin >> monto;
                cuenta->retirar(monto);
            }
            else {
                cout << "Cuenta inválida.\n";
            }
            break;

        case 3:
            cout << "Seleccione cuenta origen (1-3): ";
            cin >> idCuenta;
            cuenta = seleccionarCuenta(idCuenta);
            cout << "Seleccione cuenta destino (1-3): ";
            cin >> idDestino;
            destino = seleccionarCuenta(idDestino);
            if (cuenta && destino) {
                cout << "Ingrese monto a transferir: ";
                cin >> monto;
                cuenta->transferir(*destino, monto);
            }
            else {
                cout << "Cuenta inválida.\n";
            }
            break;

        case 4:
            cout << "Seleccione cuenta (1-3): ";
            cin >> idCuenta;
            cuenta = seleccionarCuenta(idCuenta);
            if (cuenta) {
                cuenta->mostrarSaldo();
            }
            else {
                cout << "Cuenta inválida.\n";
            }
            break;

        case 5:
            cout << "Saliendo del programa...\n";
            break;

        default:
            cout << "Opción no válida. Intente de nuevo.\n";
            break;
        }
    } while (opcion != 5);
}

int main() {
    menu();
    return 0;
}

//cuentas de banco 