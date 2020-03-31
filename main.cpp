#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string leerGenoma(const string& rutaArchivo, fstream &objArchivo, ios_base::openmode modoArchivo) {
    bool comienzaLeer = false;
    string concatenarGenoma, cadenaCompleta;
    objArchivo.open(rutaArchivo, modoArchivo);
    if (!objArchivo) {
        cerr << "Error al leer el genoma";
        exit(1);
    }
    while (objArchivo >> concatenarGenoma) {
        if (comienzaLeer) {
            cadenaCompleta.append(concatenarGenoma);
        }
        if (concatenarGenoma == "genome") {
            comienzaLeer = true;
        }
    }
    return cadenaCompleta;
}

int main() {
    fstream G1, G2;
    string Genoma1 = leerGenoma("../MN908947.txt", G1, ios::in);
    string Genoma2 = leerGenoma("../MN988669.txt", G2, ios::in);

    cout << "Genoma 1: " << Genoma1.length() << " bases nitrogenadas." << endl;
    cout << "Genoma 2: " << Genoma2.length() << " bases nitrogenadas." << endl;

    double basesIguales = 0;

    const char *pointerG1 = Genoma1.c_str();
    const char *pointerG2 = Genoma2.c_str();

    for (int i=0; *pointerG1!='\0'; i++) {
        for (int j=0; *pointerG2!='\0'; j++) {
            if (*pointerG1 == *pointerG2) {
                basesIguales++;
            } else {
                break;
            }
            (*pointerG2++);
        }
        *pointerG1++;
    }

    double igualesG1 = (basesIguales / Genoma1.length()) * 100.0;
    double igualesG2 = (basesIguales / Genoma2.length()) * 100.0;

    cout << "El " << igualesG1 << "% del Genoma 1 es igual al " << igualesG2 << "% del Genoma 2.";
    
    return 0;
}