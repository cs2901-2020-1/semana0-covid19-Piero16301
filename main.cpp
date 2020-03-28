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
    string Genoma1 = leerGenoma("../AY274119.txt", G1, ios::in);
    string Genoma2 = leerGenoma("../AY278488.2.txt", G2, ios::in);

    cout << "Genoma 1: " << Genoma1.length() << " bases nitrogenadas." << endl;
    cout << "Genoma 2: " << Genoma2.length() << " bases nitrogenadas." << endl;

    int caracteresComunes = 0, cadenaCorta;
    if (Genoma1 == Genoma2) {
        cout << "Los genomas son iguales.";
        return 0;
    } else {
        if (Genoma1 > Genoma2) {
            cadenaCorta = Genoma2.size();
        } else {
            cadenaCorta = Genoma1.size();
        }
        for(int i = 0; i != cadenaCorta; ++i){
            if (Genoma1[i] == Genoma2[i]) {
                ++caracteresComunes;
            }
        }
    }

    cout << (caracteresComunes * 100)/Genoma1.length() << "% del Genoma 1 es identico en el Genoma 2.";
    
    return 0;
}
