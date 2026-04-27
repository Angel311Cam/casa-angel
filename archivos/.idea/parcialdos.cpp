#include <iostream>
#include <fstream>
#include <string>

using namespace std;

float calcularTotal(int cantidad, float precio) {
    return cantidad * precio;
}

void registrarVenta() {
    fstream archivo("ventas.txt", ios::out | ios::app);

    string producto;
    int cantidad;
    float precio;

    cin.ignore();
    cout << "Producto: ";
    getline(cin, producto);

    cout << "Cantidad: ";
    cin >> cantidad;
    while (cantidad <= 0) {
        cout << "Error, ingrese cantidad mayor a 0: ";
        cin >> cantidad;
    }

    cout << "Precio: ";
    cin >> precio;
    while (precio <= 0) {
        cout << "Error, ingrese precio valido: ";
        cin >> precio;
    }

    float total = calcularTotal(cantidad, precio);

    archivo << producto << "," << cantidad << "," << precio << "," << total << endl;

    archivo.close();

    cout << "Venta guardada correctamente.\n";
}

void mostrarVentas() {
    ifstream archivo("ventas.txt", ios::in);
    string linea;

    cout << "\n--- LISTADO DE VENTAS ---\n";

    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();
}

void reporteVentas() {
    ifstream archivo("ventas.txt", ios::in);

    string producto;
    int cantidad;
    float precio, total;

    float suma = 0;
    int contador = 0;

    while (archivo >> producto) {
        archivo.ignore();
        archivo >> cantidad;
        archivo.ignore();
        archivo >> precio;
        archivo.ignore();
        archivo >> total;

        suma += total;
        contador++;
    }

    if (contador == 0) {
        cout << "No hay ventas registradas.\n";
    }
    else if (suma > 1000 && contador >= 1) {
        cout << "Ventas ALTAS.\n";
    }
    else {
        cout << "Ventas NORMALES.\n";
    }

    cout << "Total vendido: Q" << suma << endl;

    archivo.close();
}

void buscarVenta() {
    ifstream archivo("ventas.txt", ios::in);

    string linea, buscar;
    int contador = 0;

    cin.ignore();
    cout << "Ingrese producto a buscar: ";
    getline(cin, buscar);

    for (int i = 0; i < 1000; i++) {

        if (!getline(archivo, linea)) {
            break;
        }

        if (linea.find(buscar) == string::npos) {
            continue;
        }

        cout << linea << endl;
        contador++;
    }

    if (contador == 0) {
        cout << "No se encontraron resultados.\n";
    }

    archivo.close();
}

void menu() {
    int opcion;

    do {
        cout << "\n===== SISTEMA DE VENTAS =====\n";
        cout << "Bienvenido al parcial Angel Estuardo Campos Santay 9941-45-4809\n";
        cout << "1. Registrar venta\n";
        cout << "2. Mostrar ventas\n";
        cout << "3. Reporte\n";
        cout << "4. Buscar producto\n";
        cout << "5. Salir\n";
        cout << "Seleccione: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarVenta();
                break;

            case 2:
                mostrarVentas();
                break;

            case 3:
                reporteVentas();
                break;

            case 4:
                buscarVenta();
                break;

            case 5:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida\n";
        }

    } while (opcion != 5);
}

int main() {
    menu();
    return 0;
}