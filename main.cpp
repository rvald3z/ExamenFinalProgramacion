#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

struct Registro {
    string carne;
    string nombre;
    int edad;
    char sexo;
    int matematica;
    int ciencias;
    int computacion;
    int fisica;
    int idioma;
    int literatura;
};

vector<Registro> registros;

void MockData() {
    Registro registroNuevo;
    registroNuevo.carne = "CS123";
    registroNuevo.nombre = "Carlos Suarez";
    registroNuevo.edad = 20;
    registroNuevo.sexo = 'M';
    registroNuevo.matematica = 60;
    registroNuevo.ciencias = 70;
    registroNuevo.computacion = 80;
    registroNuevo.fisica = 90;
    registroNuevo.idioma = 100;
    registroNuevo.literatura = 50;
    registros.push_back(registroNuevo);
}
void puntoUno(){
    int noRegistros;
    cout << "Ingrese el número de registros que quieres ingresar: ";
    cin >> noRegistros;
    for (int i = 0; i < noRegistros; ++i) {
        Registro registroNuevo;
        cout << "Ingrese el carné del estudiante No." << i + 1 << ": ";
        cin >> registroNuevo.carne;
        cout << "Ingrese el nombre del estudiante No." << i + 1 << ": ";
        cin >> registroNuevo.nombre;
        cout << "Ingrese la edad del estudiante No." << i + 1 << ": ";
        cin >> registroNuevo.edad;
        cout << "Ingrese el sexo del estudiante (M/F) No." << i + 1 << ": ";
        cin >> registroNuevo.sexo;
        cout << "Ingrese la nota de matemáticas del estudiante No." << i + 1 << ": ";
        cin >> registroNuevo.matematica;
        cout << "Ingrese la nota de ciencias del estudiante No." << i + 1 << ": ";
        cin >> registroNuevo.ciencias;
        cout << "Ingrese la nota de computación del estudiante No." << i + 1 << ": ";
        cin >> registroNuevo.computacion;
        cout << "Ingrese la nota de física del estudiante No." << i + 1 << ": ";
        cin >> registroNuevo.fisica;
        cout << "Ingrese la nota de idioma del estudiante No." << i + 1 << ": ";
        cin >> registroNuevo.idioma;
        cout << "Ingrese la nota de literatura del estudiante " << i + 1 << ": ";
        cin >> registroNuevo.literatura;
        registros.push_back(registroNuevo);
    }
}
void puntoDos() {
    int m = 0;
    int h = 0;
    for (const Registro& registro : registros) {
        if (registro.sexo == 'M' || registro.sexo == 'm') {
            m++;
        } else if (registro.sexo == 'H' || registro.sexo == 'h') {
            h++;
        }
    }
    cout << "El número de hombres es: " << h << " y el número de mujeres es: " << m << endl;
}
void puntoTres() {
    vector<Registro> masJovenes;
    int edadMinima = registros[0].edad;

    for (const Registro& registro : registros) {
        if (registro.edad < edadMinima) {
            edadMinima = registro.edad;
            masJovenes.push_back(registro);
        } else if (registro.edad == edadMinima) {
            masJovenes.push_back(registro);
        }
    }

    cout << "El alumno o los alumnos más jóvenes son:" << endl;
    for (const Registro& joven : masJovenes) {
        cout << "Nombre: " << joven.nombre << ", Edad: " << joven.edad << endl;
    }
}
void puntoCuatro() {
    for (const Registro& registro : registros) {
        if (registro.nombre == "Carlos Suarez") {
            int clasesReprobadas = 0;
            if (registro.matematica < 61) clasesReprobadas++;
            if (registro.ciencias < 61) clasesReprobadas++;
            if (registro.computacion < 61) clasesReprobadas++;
            if (registro.fisica < 61) clasesReprobadas++;
            if (registro.idioma < 61) clasesReprobadas++;
            if (registro.literatura < 61) clasesReprobadas++;
            cout << "Carlos Suarez tiene " << clasesReprobadas << " clases reprobadas." << endl;
        }
    }
}
void puntoCinco() {
    cout << "Los alumnos que aprobaron todos los cursos son:" << endl;
    for (const Registro& registro : registros) {
        if (registro.matematica >= 61 && registro.ciencias >= 61 && registro.computacion >= 61 &&
            registro.fisica >= 61 && registro.idioma >= 61 && registro.literatura >= 61) {
            cout << registro.carne << registro.nombre << endl;
        }
    }
}
void puntoSeis() {
}
void puntoSiete(){
}
void puntoOcho() {
    int sumaNotas = 0;
    for (const Registro& registro : registros) {
        sumaNotas += registro.matematica;
    }
    float promedio = sumaNotas / registros.size();

    cout << "La nota promedio en el curso de Matemáticas es de: " << promedio << endl;
}
void puntoNueve(){
}
void puntoDiez(){
}

int main() {
    bool salir = false;
    int opcion;
    MockData();
    do {
        cout << "1. Ingresar registros\n";
        cout << "2. No. Alumnos hombres y mujeres\n";
        cout << "3. Quienes son los alumnos mas jovenes\n";
        cout << "4. Clases reprobadas por Carlos Suarez\n";
        cout << "5. Alumnos que aprobaron todos los cursos\n";
        cout << "6. Alumnos con el promedio más alto\n";
        cout << "7. Alumnos con el promedio más bajo\n";
        cout << "8. Promedio del curso de Matemáticas\n";
        cout << "9. Hombre y mujer con mayor promedio en Matemática, Computación y Física\n";
        cout << "10. Alumno que reprobó más cursos\n";
        cout << "11. Salir\n";
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                puntoUno();
                break;
            case 2:
                puntoDos();
                break;
            case 3:
                puntoTres();
                break;
            case 4:
                puntoCuatro();
                break;
            case 5:
                puntoCinco();
                break;
            case 6:
                puntoSeis();
                break;
            case 7:
                puntoSiete();
                break;
            case 8:
                puntoOcho();
                break;
            case 9:
                puntoNueve();
                break;
            case 10:
                puntoDiez();
                break;
            case 11:
                salir = true;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (!salir);

    return 0;
}
