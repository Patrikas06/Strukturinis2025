#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

void skaiciuotiBilietus() {
    string inputFailas = "Biletai.txt";
    string outputFailas = "Rezultatas.txt";

    ifstream in(inputFailas);
    ofstream out(outputFailas);

    

    double kaina;
    int kiekis;
    double bendraSuma = 0;
    int BilietuKiekis = 0;
    double suma;

    while (in >> kaina >> kiekis) {
         suma = kaina * kiekis;
        BilietuKiekis += kiekis;
        bendraSuma += suma;
    }


    cout << "Parduota bilietu " << BilietuKiekis << endl;
    cout << "Bendra pardavimu suma " << bendraSuma << " EUR" << endl;
out << fixed << setprecision(2);

    out << "Parduota bilietu " << BilietuKiekis << endl;
    out << "Bendra pardavimu suma " << bendraSuma << " EUR" << endl;
out << fixed << setprecision(2);
    in.close();
    out.close();

    cout << endl << "Rezultatai irasyti i faila " << outputFailas << endl;
}

void atnaujintiAtlyginimus() {
    string inputFailas = "atlyginimas.txt";
    string outputFailas = "naujas.txt";

    ifstream in(inputFailas);
    ofstream out(outputFailas);

    string pavarde, vardas;
    float atlyginimas, pr;
    float naujasAtlyginimas;

    while (in >> pavarde >> vardas >> atlyginimas >> pr) {
         naujasAtlyginimas = atlyginimas + (atlyginimas * pr / 100.0);
        cout << pavarde << " " << vardas << " " << naujasAtlyginimas << " USD" << endl;
        out << pavarde << " " << vardas << " " << naujasAtlyginimas << " USD" << endl;
        out << fixed << setprecision(2);
    }

    in.close();
    out.close();

    cout << "Rezultatai irasyti i faila " << outputFailas << endl;
}

int main() {
    int pasirinkimas = -1;

    while (pasirinkimas != 0) {
        cout << "1 Skaiciuoti bilietu pardavimu suma" << endl;
        cout << "2 Atnaujinti darbuotoju atlyginimus" << endl;
        cout << "0 Iseiti" << endl;
        cout << "Pasirinkite ";
        cin >> pasirinkimas;

        if (pasirinkimas == 1) {
            skaiciuotiBilietus();
        }
        else if (pasirinkimas == 2) {
            atnaujintiAtlyginimus();
        }
        else if (pasirinkimas == 0) {
            cout << "Programa baige darba" << endl;
        }
       
    }

    return 0;
}
