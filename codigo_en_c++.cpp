

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <limits>
#include <vector>

 
using namespace std;
 
// PROTOTIPOS DE FUNCIONES
void mostrarMenu();
void operacionesMatematicas();
void registroNotas();
void guardarResultados(string nombreEstudiante, double resultados[], int n,
                       double promedio, double mayor, double menor,
                       int aprobados, int reprobados,
                       double opMat[], string operaciones[]);
string obtenerFecha();
void limpiarPantalla();
void pausar();
 
// VARIABLES GLOBALES PARA ALMACENAR RESULTADOS
double notasGlobal[5]         = {0};
double promedioGlobal         = 0;
double mayorGlobal            = 0;
double menorGlobal            = 0;
int    aprobadosGlobal        = 0;
int    reprobadosGlobal       = 0;
double resultadosMatGlobal[4] = {0}; // suma, resta, mult, div
string operacionesNombre[4]   = {"Suma", "Resta", "Multiplicacion", "Division"};
bool   notasRegistradas       = false;
bool   matRegistradas         = false;
string nombreEstudiante       = "";
 
// FUNCION PRINCIPAL
int main() {
    vector<string> estudiantes = {
        "ACOSTA SOLIS HANNA AIDE",
        "ANDRADE SANCHEZ HUGO ALEXANDER",
        "ATIENCIA CHERRES JOSUE ALEXANDER",
        "BALAREZO PEREZ DIEGO SEBASTIAN",
        "BARRIONUEVO MONTESDEOCA JOB GABRIEL",
        "BEDOYA MAZO JUAN MANUEL",
        "BRAVO LOPEZ JORDAN SAMUEL",
        "CAIZA CAIZABUANO JOSE RUBEN",
        "CAJIAO VALDIVIESO PAULO ALESSANDRO",
        "CALVOPIÑA HERRERA BRANDON ISRAEL",
        "CASTELO BERRONES KATHERINE NICOL",
        "CHACHA CHANGO VICTOR MANUEL",
        "CHILUIZA QUISHPE DIEGO STEED",
        "DOMINGUEZ LESCANO DANIEL SEBASTIAN",
        "FREIRE AREBALO ALAN ANDERSON",
        "GUALLE AUCANSHALA ABISAG LISENIA",
        "GUAMAN CHANAHUANO HAMILTON ALEXANDER",
        "GUANGA ALTAMIRANO EDWIN SEBASTIAN",
        "GUANOTOA ESCOBAR KARLA LEONELA",
        "LANDETA TAPIA EDISON PAUL",
        "LARA BALSECA KAREN ARACELY",
        "LOOR VELEZ JHON ALEJANDRO",
        "LOPEZ SANCHEZ WASHINGTON STEVEN",
        "MIRANDA GARCES ALAN IMANOL",
        "MONAR PARCO JHAIR ALEXANDER",
        "MUYULEMA MOYOLEMA MATEO ALEXANDER",
        "NARVAEZ GAVILANES ANTONELLA NICOLE",
        "NUÑEZ ESPIN BRYAN SEBASTIAN",
        "PILCO FLORES MARIO DAVID",
        "POMAQUERO CHANGO KATHERINE SOLEDAD",
        "QUEVEDO AJON GINA ANAHI",
        "RIVADENEYRA ULLOA MATIAS SEBASTIAN",
        "ROCHA ROCHA CAROLINA ESTEFANIA",
        "SANCHEZ LEMA ISAAC ADRIAN",
        "SEGOVIA GARCIA JOSEPH ANDRE",
        "SUPE GARCES JOAN SEBASTIAN",
        "TOAPANTA IZA KEVIN MATIAS",
        "VERDESOTO AZOGUE KEVIN ALEXANDER",
        "VILLACRES TOALOMBO JOSUE ALEJANDRO",
        "VITERI CAMINO MAYDELIN SHANTAL"
    };

    int opcion;

    cout << "=============================================" << endl;
    cout << "   APLICATIVO INTERACTIVO - UTA 2026        " << endl;
    cout << "   Algoritmos y Logica de Programacion      " << endl;
    cout << "=============================================" << endl;

    for (int i = 0; i < estudiantes.size(); i++) {
        nombreEstudiante = estudiantes[i];

        notasRegistradas = false;
        matRegistradas = false;

        cout << "\n=============================================" << endl;
        cout << " Estudiante actual: " << nombreEstudiante << endl;
        cout << "=============================================" << endl;

        do {
            mostrarMenu();
            cout << "Seleccione una opcion: ";
            cin >> opcion;

            while (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Opcion invalida. Ingrese un numero: ";
                cin >> opcion;
            }
            cin.ignore();

            switch (opcion) {
                case 1:
                    operacionesMatematicas();
                    break;

                case 2:
                    registroNotas();
                    break;

                case 3:
                    guardarResultados(nombreEstudiante, notasGlobal, 5,
                                      promedioGlobal, mayorGlobal, menorGlobal,
                                      aprobadosGlobal, reprobadosGlobal,
                                      resultadosMatGlobal, operacionesNombre);
                    break;

                case 4:
                    cout << "\nPasando al siguiente estudiante..." << endl;
                    break;

                default:
                    cout << "\n[!] Opcion no valida. Intente de nuevo." << endl;
                    pausar();
            }

        } while (opcion != 4);
    }

    cout << "\nTodos los estudiantes fueron procesados." << endl;

    return 0;
} 
// MENU INTERACTIVO
void mostrarMenu() {
    cout << "\n=============================================" << endl;
    cout << "   MENU PRINCIPAL" << endl;
    cout << "   Bienvenido, " << nombreEstudiante << endl;
    cout << "=============================================" << endl;
    cout << "  1. Operaciones basicas" << endl;
    cout << "  2. Registro de notas" << endl;
    cout << "  3. Guardar resultados" << endl;
    cout << "  4. Salir" << endl;
    cout << "=============================================" << endl;
}
 
// PARTE 2 — OPERACIONES MATEMATICAS
void operacionesMatematicas() {
    double a, b;
    int subopcion;
 
    cout << "\n--- OPERACIONES MATEMATICAS ---" << endl;
    cout << "Ingrese el primer numero : ";
    cin >> a;
    cout << "Ingrese el segundo numero: ";
    cin >> b;
 
    // Acumulador de resultados
    double suma  = a + b;
    double resta = a - b;
    double mult  = a * b;
 
    cout << "\n  [1] Suma           : " << a << " + " << b << " = " << suma  << endl;
    cout << "  [2] Resta          : " << a << " - " << b << " = " << resta << endl;
    cout << "  [3] Multiplicacion : " << a << " * " << b << " = " << mult  << endl;
 
    // Validacion de division para cero (operador relacional)
    if (b != 0) {
        double division = a / b;
        cout << "  [4] Division       : " << a << " / " << b << " = " << fixed << setprecision(4) << division << endl;
        resultadosMatGlobal[3] = division;
    } else {
        cout << "  [4] Division       : No permitida (division para cero)" << endl;
        resultadosMatGlobal[3] = 0;
    }
 
    // Guardar resultados en variables globales
    resultadosMatGlobal[0] = suma;
    resultadosMatGlobal[1] = resta;
    resultadosMatGlobal[2] = mult;
    matRegistradas = true;
 
    cin.ignore();
    pausar();
}
 
// PARTE 3 — ARREGLOS Y PROCESAMIENTO DE NOTAS
void registroNotas() {
    const int N = 5;
    double notas[N];
    double suma     = 0;
    double mayor    = 0;
    double menor    = 100;
    int aprobados   = 0;
    int reprobados  = 0;
 
    cout << "\n--- REGISTRO DE NOTAS ---" << endl;
    cout << "Ingrese las " << N << " notas del estudiante (0 - 10):" << endl;
 
    // Ciclo for para ingresar notas con validacion
    for (int i = 0; i < N; i++) {
        cout << "  Nota " << (i + 1) << ": ";
        cin >> notas[i];
 
        // Validar rango con while
        while (notas[i] < 0 || notas[i] > 10) {
            cout << "  [!] Nota invalida. Ingrese entre 0 y 10: ";
            cin >> notas[i];
        }
 
        // Acumulador para la suma
        suma += notas[i];
 
        // Condicional para mayor y menor
        if (notas[i] > mayor) mayor = notas[i];
        if (notas[i] < menor) menor = notas[i];
 
        // Contador de aprobados y reprobados (aprobado >= 7)
        if (notas[i] >= 7) {
            aprobados++;
        } else {
            reprobados++;
        }
    }
 
    // Calculo del promedio
    double promedio = suma / N;
 
    // Mostrar resultados
    cout << "\n--- RESULTADOS DEL ANALISIS ---" << endl;
    cout << "  Notas registradas : ";
    for (int i = 0; i < N; i++) {
        cout << notas[i];
        if (i < N - 1) cout << ", ";
    }
    cout << endl;
    cout << "  Promedio          : " << fixed << setprecision(2) << promedio << endl;
    cout << "  Nota mayor        : " << mayor    << endl;
    cout << "  Nota menor        : " << menor    << endl;
    cout << "  Aprobados         : " << aprobados   << " estudiante(s)" << endl;
    cout << "  Reprobados        : " << reprobados  << " estudiante(s)" << endl;
 
    // Guardar en variables globales
    for (int i = 0; i < N; i++) notasGlobal[i] = notas[i];
    promedioGlobal   = promedio;
    mayorGlobal      = mayor;
    menorGlobal      = menor;
    aprobadosGlobal  = aprobados;
    reprobadosGlobal = reprobados;
    notasRegistradas = true;
 
    cin.ignore();
    pausar();
}
 
// PARTE 4 — PERSISTENCIA EN ARCHIVOS
void guardarResultados(string nombre, double notas[], int n,
                       double promedio, double mayor, double menor,
                       int aprobados, int reprobados,
                       double opMat[], string operaciones[]) {
 
    if (!notasRegistradas && !matRegistradas) {
        cout << "\n  [!] No hay resultados que guardar." << endl;
        cout << "      Use las opciones 1 y 2 primero." << endl;
        pausar();
        return;
    }
 
    ofstream archivo("resultados.txt", ios::app); // append para no sobrescribir
 
    if (!archivo.is_open()) {
        cout << "\n  [!] Error al abrir el archivo resultados.txt" << endl;
        pausar();
        return;
    }
 
    archivo << "=============================================" << endl;
    archivo << "  REPORTE DE RESULTADOS" << endl;
    archivo << "=============================================" << endl;
    archivo << "  Nombre del estudiante : " << nombre << endl;
    archivo << "  Fecha y hora          : " << obtenerFecha() << endl;
    archivo << "  Lenguaje utilizado    : C++" << endl;
    archivo << "  Universidad           : Universidad Tecnica de Ambato" << endl;
    archivo << "  Asignatura            : Algoritmos y Logica de Programacion" << endl;
    archivo << "---------------------------------------------" << endl;
 
    if (matRegistradas) {
        archivo << "\n  OPERACIONES MATEMATICAS:" << endl;
        for (int i = 0; i < 4; i++) {
            archivo << "    " << operaciones[i] << " : " << fixed << setprecision(4) << opMat[i] << endl;
        }
    }
 
    if (notasRegistradas) {
        archivo << "\n  REGISTRO DE NOTAS:" << endl;
        archivo << "    Notas      : ";
        for (int i = 0; i < n; i++) {
            archivo << notas[i];
            if (i < n - 1) archivo << ", ";
        }
        archivo << endl;
        archivo << "    Promedio   : " << fixed << setprecision(2) << promedio   << endl;
        archivo << "    Mayor      : " << mayor    << endl;
        archivo << "    Menor      : " << menor    << endl;
        archivo << "    Aprobados  : " << aprobados   << endl;
        archivo << "    Reprobados : " << reprobados  << endl;
    }
 
    archivo << "\n=============================================" << endl;
    archivo << endl;
    archivo.close();
 
    cout << "\n  [OK] Resultados guardados en 'resultados.txt' correctamente." << endl;
    pausar();
}
 
// UTILIDADES
string obtenerFecha() {
    time_t ahora = time(0);
    char buffer[80];
    struct tm* info = localtime(&ahora);
    strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", info);
    return string(buffer);
}
 
void pausar() {
    cout << "\n  Presione Enter para continuar...";
    cin.get();
}
 