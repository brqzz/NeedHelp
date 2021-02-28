#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#define CHARCOUNT 20
using namespace std;

class Kava
{
private: //Apibrėžia kintamuosius
    string StrPavadinimas;
    string StrRusis;
    string StrGamintojas;
    double doubleKaina, doubleSvoris;

public:
    Kava() {  //Nunulina reikšmes
        StrPavadinimas = "";
        StrRusis = "";
        StrGamintojas = "";
        doubleKaina = 0;
        doubleSvoris = 0;

    }
    void set_Kava(string StrP, string StrR, string StrG, double doubleK, double doubleS)
    {
        StrPavadinimas = StrP;
        StrRusis = StrR;
        StrGamintojas = StrG;
        doubleKaina = doubleK;
        doubleSvoris = doubleS;
    }

    void SukurtiDuomenis(int n)
    {
        //int m;
        //m = n;

        

        ofstream KAVA("kava.txt");
        string StrP[n];
        string StrR[n];
        string StrG[n];
        double doubleK[n];
        double doubleS[n];


        for (int i = 0; i < n; i++)
        {

            cout << n << "  " << i << "\n";
            cout << "Įveskite " << i + 1 << " kavos pavadinimą: ";
            cin >> StrP[i];
            KAVA << i + 1 << " " << StrP[i];
            cout << std::endl;

            cout << "Įveskite " << i + 1 << " kavos rušį: ";
            cin >> StrR[i];
            KAVA << " " << StrR[i] << " ";
            cout << std::endl;

            cout << "Įveskite " << i + 1 << " kavos gamintoją: ";
            cin >> StrG[i];
            KAVA << StrG[i];
            cout << std::endl;

            cout << "Įveskite "<< i+1 << " kavos kainą: ";
            cin >> doubleK[i];
            cout <<  endl;

            cout << "Įveskite "<< i+1 << " kavos svorį: ";
            cin >> doubleS[i];
            cout <<  endl;

            if (n != i + 1)
            {
                KAVA << "\n";
            }
        }

        KAVA.close();
    }

    void atspauzdintiFaila(int n)
    {
        ifstream KAVA("kava.txt");
        for (int i = 0; i <= n; i++)
        {

            cout << StrPavadinimas << "\t" << StrRusis << "\t" << StrGamintojas << "\t";
            // doubleKaina << "\t" << doubleSvoris;
        }
    }


    void set_pavadinimas(string StrP) { StrPavadinimas = StrP; }
    void set_rusis(string StrR) { StrRusis = StrR; }
    void set_gamintojas(string StrG) { StrGamintojas = StrG; }
    void set_kaina(double doubleK) { doubleKaina = doubleK; }
    void set_svoris(double doubleS) { doubleSvoris = doubleS; }
    string get_pavadinimas() { return StrPavadinimas; }
    string get_rusis() { return StrRusis; }
    string get_gamintojas() { return StrGamintojas; }
    double get_kaina() { return doubleKaina; }
    double get_svoris() { return doubleSvoris; }
    //double vidurkis() {return ((doubleKa;}

};

class KavosSarasas
{
private:
    int n;
    Kava K[CHARCOUNT];
public:

    Kava f(string vardas)

    {
        n = 0;
        string StrP, StrR, StrG;
        int doubleK, doubleS;
        ifstream f(vardas);
        if (f.fail())
        {
            cout << "Nera failo";
        }
        else
        {
            while (!f.eof())
            {
                f >> StrP >> StrR >> StrG >> doubleK >> doubleS;
                K[n].set_Kava(StrP, StrR, StrG, doubleK, doubleS);
                cout << "\n";
                n++;
            }
        }
        f.close();
    };
    void BendrasVidurkis()
    {
        double x = 0;
        for (int i = 0; i < n; i++) { x += K[i].get_kaina(); }
        x /= n;
        cout << "Bendras vidurkis " << fixed << setprecision(2) << x << endl;
    }
};


int main()
{
    int n;
    Kava Kava;
    //KavosSarasas KAVAS;
    ifstream KAVA;
    KAVA.open("kava.txt", ios::in);
    if (KAVA)
    {
        //KAVA.vidurkis();

    }

    else
    {

        cout << "Įveskite kelias skirtingas kavas norite įtraukti į sarašą: ";
        cin >> n;
        cout << endl;

        KAVA.open("kava.txt", ios::out);

        Kava.SukurtiDuomenis(n);
        Kava.atspauzdintiFaila(n);

    }

}