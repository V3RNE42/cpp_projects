#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std; /* Written by Julio Cabanillas - juliocabanillas42@gmail.com */
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    string grupo[14] = {"", "", "", "", "", "", "", "", "", "", "", "", "", ""}; /* EMPTY GROUPINGS */
    string clase[14] = {"Alberto", "Angel", "Antonio", "Carlos", "David",        /* STUDENTS */
                        "Felipe", "Ignacio", "JaviG", "JaviS", "Julio",
                        "Lana", "Nuno", "Pedro", "Rafa"};
    int contador, num, TOTAL, GRUPO;
    TOTAL = 14;                                                                  /* Number of students == 14 */

    do
    {
        cout << endl
             << "Tenemos " << TOTAL << " alumnos" << endl;
        GRUPO = TOTAL;
        while (GRUPO >= TOTAL || GRUPO <= 1)
        {
            cout << "¿Cuántos alumnos debe tener cada grupo como máximo?" << endl;
            cin >> GRUPO;
        }

        int agrupado = 0, contador = 0;
        while (agrupado < TOTAL)
        {
            cout << endl
                 << endl
                 << "Grupo " << contador + 1 << ": "; /* First (and consecutive non-final) runnings of the while loop*/
            if (TOTAL % GRUPO != (TOTAL - agrupado)   /* IF TOTAL%GRUPO != 0 */
            && ((contador + 1) * GRUPO) < TOTAL)      /* IF TOTAL%GRUPO == 0 */
            { 
                for (int i = 0; i < GRUPO; i++)
                {
                    srand(time(NULL));
                    int entero = rand() % (TOTAL - agrupado);
                    grupo[agrupado] = clase[entero];
                    clase[entero] = clase[TOTAL - agrupado - 1];
                    clase[TOTAL - agrupado - 1] = "";
                    agrupado++;
                }
                for (int i = agrupado - GRUPO; i < agrupado; i++)
                {
                    cout << grupo[i] << " ";
                }
            }
            else
            { /*Last running of the loop*/
                int temp = TOTAL - agrupado;
                for (int i = 0; i < temp; i++)
                {
                    cout << clase[i] << " ";
                    grupo[agrupado] = clase[i];
                    clase[i] = "";
                    agrupado++;
                }
            }
            contador++;
        }

        for (int i = 0; i < TOTAL; i++)
        { /* "Reset" of both arrays */
            clase[i] = grupo[i];
            grupo[i] = "";
        }
        cout << endl
             << endl;
        system("PAUSE");
        system("CLS");
    } while (true);
    return 0;
}