#include <iostream>
#include <string>

using namespace std;

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

// Creación de 30 cuentas sin usar arreglos ni vectores
CuentaBancaria c1("Juan Perez", 500);
CuentaBancaria c2("Maria Lopez", 1200);
CuentaBancaria c3("Carlos Sanchez", 300);
CuentaBancaria c4("Luis Gomez", 700);
CuentaBancaria c5("Ana Martinez", 150);
CuentaBancaria c6("Pedro Castillo", 1000);
CuentaBancaria c7("Sofia Ramirez", 400);
CuentaBancaria c8("Andres Mendoza", 800);
CuentaBancaria c9("Beatriz Flores", 600);
CuentaBancaria c10("Roberto Torres", 200);
CuentaBancaria c11("Elena Vargas", 50);
CuentaBancaria c12("Fernando Ortega", 900);
CuentaBancaria c13("Laura Rios", 1100);
CuentaBancaria c14("Gabriel Soto", 250);
CuentaBancaria c15("Diana Fernandez", 450);
CuentaBancaria c16("Oscar Herrera", 350);
CuentaBancaria c17("Patricia Guzman", 550);
CuentaBancaria c18("Alberto Jimenez", 650);
CuentaBancaria c19("Raquel Castro", 750);
CuentaBancaria c20("Esteban Navarro", 850);
CuentaBancaria c21("Monica Del Valle", 950);
CuentaBancaria c22("Ricardo Estrada", 1050);
CuentaBancaria c23("Lucia Morales", 1150);
CuentaBancaria c24("Enrique Paredes", 1250);
CuentaBancaria c25("Valeria Acosta", 1300);
CuentaBancaria c26("Gustavo Carrillo", 1400);
CuentaBancaria c27("Carmen Vega", 500);
CuentaBancaria c28("Jorge Silva", 600);
CuentaBancaria c29("Mariana Espinoza", 700);
CuentaBancaria c30("Hugo Alvarado", 800);

// Función para seleccionar una cuenta
CuentaBancaria* seleccionarCuenta(int id) {
    switch (id) {
    case 1: return &c1;
    case 2: return &c2;
    case 3: return &c3;
    case 4: return &c4;
    case 5: return &c5;
    case 6: return &c6;
    case 7: return &c7;
    case 8: return &c8;
    case 9: return &c9;
    case 10: return &c10;
    case 11: return &c11;
    case 12: return &c12;
    case 13: return &c13;
    case 14: return &c14;
    case 15: return &c15;
    case 16: return &c16;
    case 17: return &c17;
    case 18: return &c18;
    case 19: return &c19;
    case 20: return &c20;
    case 21: return &c21;
    case 22: return &c22;
    case 23: return &c23;
    case 24: return &c24;
    case 25: return &c25;
    case 26: return &c26;
    case 27: return &c27;
    case 28: return &c28;
    case 29: return &c29;
    case 30: return &c30;
    default: return nullptr;
    }
}

// Función del menú
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
            cout << "Seleccione cuenta (1-30): ";
            cin >> idCuenta;
            cuenta = seleccionarCuenta(idCuenta);
            if (cuenta) {
                cout << "Ingrese monto a depositar: ";
                cin >> monto;
                cuenta->depositar(monto);
            }
            break;
        case 2:
            cout << "Seleccione cuenta (1-30): ";
            cin >> idCuenta;
            cuenta = seleccionarCuenta(idCuenta);
            if (cuenta) {
                cout << "Ingrese monto a retirar: ";
                cin >> monto;
                cuenta->retirar(monto);
            }
            break;
        case 3:
            cout << "Seleccione cuenta origen (1-30): ";
            cin >> idCuenta;
            cuenta = seleccionarCuenta(idCuenta);
            cout << "Seleccione cuenta destino (1-30): ";
            cin >> idDestino;
            destino = seleccionarCuenta(idDestino);
            if (cuenta && destino) {
                cout << "Ingrese monto a transferir: ";
                cin >> monto;
                cuenta->transferir(*destino, monto);
            }
            break;
        case 4:
            cout << "Seleccione cuenta (1-30): ";
            cin >> idCuenta;
            cuenta = seleccionarCuenta(idCuenta);
            if (cuenta) cuenta->mostrarSaldo();
            break;
        }
    } while (opcion != 5);
}

int main() {
    menu();
    return 0;
}
