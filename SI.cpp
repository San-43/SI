#include <iostream>
#include <limits>
#include <cstring>

char askOption();
bool askForBack();
double value(double x, char unidad);
void cmTOin();
void mTOft();
void kmTOmi();
void gTOoz();
void kgTOlb();

const char pass[9] = "password";


using namespace std;

int main() {
    bool back = false;
    char magicWord[9];
    int temp = 2;

    system("color 02");
    setlocale(LC_CTYPE, "spanish");

    do {
        cout << "Ingrese la contraseña: \n";
        cin.getline(magicWord, 9);
        if (strcmp(pass, magicWord) == 0) {
            break;
        } else {
            if (temp != 0) {
                cout << "Contraseña incorrecta, vuelva a intentarlo. Intentos restantes: " << temp << "\n";
                temp--;
            } else {
                return 0;
            }
        }

    } while (true);


    do {
        system("cls");
        system("color 02");
        setlocale(LC_CTYPE, "spanish");

        cout<<"\t"<<"##     ## ######## ##    ## ##     ##"<<endl;
        cout<<"\t"<<"###   ### ##       ###   ## ##     ##"<<endl;
        cout<<"\t"<<"#### #### ##       ####  ## ##     ##"<<endl;
        cout<<"\t"<<"## ### ## ######   ## ## ## ##     ##"<<endl;
        cout<<"\t"<<"##     ## ##       ##  #### ##     ##"<<endl;
        cout<<"\t"<<"##     ## ##       ##   ### ##     ##"<<endl;
        cout<<"\t"<<"##     ## ######## ##    ##  #######"<<endl;

        cout<<"\t"<<"*************************************"<<endl;
        cout<<"\t"<<"***   1) o A) Unidades de Lóngitud                ***"<<endl;
        cout<<"\t"<<"***   2) o B) Unidades de Masa                ***"<<endl;
        cout<<"\t"<<"***   0) o Q) Salir de la aplicación                ***"<<endl;
        cout<<"\t"<<"*************************************"<<endl;

        switch (askOption()) {
            case '1': case 'A':
                cout<<"\t"<<"*************************************"<<endl;
                cout<<"\t"<<"***   1) o A) cm -> in                ***"<<endl;
                cout<<"\t"<<"***   2) o B) m -> ft                ***"<<endl;
                cout<<"\t"<<"***   3) o C) Km -> mi               ***"<<endl;
                cout<<"\t"<<"***   0) o Q) Volver al menú principal                ***"<<endl;
                cout<<"\t"<<"*************************************"<<endl;

                switch (askOption()) {
                    case '1': case 'A':
                        cmTOin();
                        break;
                    case '2': case 'B':
                        mTOft();
                        break;
                    case '3': case 'C':
                        kmTOmi();
                        break;
                    case '0': case 'Q':
                        back = true;
                        break;
                    default:
                        back = false;
                        cout << "Opción incorrecta, por favor... revice las opciones e ingrese una correcta." << endl;
                }
                break;
            case '2': case 'B':
                cout<<"\t"<<"*************************************"<<endl;
                cout<<"\t"<<"***   1) o A) g -> oz                ***"<<endl;
                cout<<"\t"<<"***   2) o B) kg -> lb                ***"<<endl;
                cout<<"\t"<<"***   0) o Q) Volver al menú principal                ***"<<endl;
                cout<<"\t"<<"*************************************"<<endl;

                switch (askOption()) {
                    case '1': case 'A':
                        gTOoz();
                        break;
                    case '2': case 'B':
                        kgTOlb();
                        break;
                    case '0': case 'Q':
                        back = true;
                        break;
                    default:
                        back = false;
                        cout << "Opción incorrecta, por favor... revice las opciones e ingrese una correcta." << endl;
                }
                break;
            case '0': case 'Q':
                return 0;
            default:
                back = false;
                cout << "Opción incorrecta, por favor... revice las opciones e ingrese una correcta....." << endl;
        }
        if(back) {
            continue;
        } else {
            back = askForBack();
        }

    }while (back);

    return 0;
}

double value(double x, const string& unidad) {
    printf("Ingrese los %s: \n", unidad.c_str());

    do {
        if (!(cin >> x) || x <= 0 ) {
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
            cout << "\nError... Valor incorrecto...\n";
        }else {
            break;
        }
    }while (true);

    return x;
}

char askOption() {
    char option;

    do {
        cout << "\t"<<"Ingrese la opción ---> ";
        cin.clear();
        cin >> option;
        if (isalnum(option) || isalpha(option)) {
            system("cls");
            if (isalpha(option)) {
                option = toupper(option);
                break;
            }
            break;
        }else {
            cout << "Error en la entrada...\n";
            cin.clear();
            cin.ignore(numeric_limits<char>::max(), '\n');
            continue;
        }
    }while (true);

    return option;
}

bool askForBack() {
    char isBack[1];

    cout << endl;
    cout << "Desea usted regresar al inicio del programa? S para SI, cualquier otra tecla para salir." << endl;

    cin >> isBack;
    if (strcmp(isBack, "s") != 0 && strcmp(isBack, "S") != 0) {
        cout << "\nBye...";
        return false;
    }
    return true;
}

void cmTOin() {
    double cm;
    cm = value(cm, "cm");
    printf("%f cm es igual aproximadamente a: %.2f in.", cm,(0.39370079 * cm));
}
void mTOft() {
    double m;
    m = value(m, "m");
    printf("%f m es igual aproximadamente a: %.2f ft.", m,(3.2808399 * m));
}
void kmTOmi() {
    double km;
    km = value(km, "km");
    printf("%f km es igual aproximadamente a: %.2f mi.", km,(0.62137119 * km));
}
void gTOoz() {
    double g;
    g = value(g, "g");
    printf("%f g es igual aproximadamente a: %.2f oz.", g,(0.03527396 * g));
}
void kgTOlb() {
    double kg;
    kg = value(kg, "kg");
    printf("%f kg es igual aproximadamente a: %.2f lb.", kg,(2.20462262 * kg));
}
