#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#define CHARCOUNT 100 //Maksimalus kavų kiekis 
using namespace std;

class Kava
{
private: //Apibrėžia kintamuosius
    string StrPavadinimas;
    string StrRusis;
    string StrGamintojas;
    double doubleKaina, doubleSvoris;

public:
    Kava() 
    {  //Nunulina reikšmes
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

        

        fstream KAVA("kava.txt");
        vector <string> StrP (n);
        vector <string> StrR (n);
        vector <string> StrG (n);
        vector <double> doubleK (n);
        vector <double> doubleS (n);


        for (int i = 0; i < n; i++)
        {
            cout << "Įveskite " << i + 1 << " kavos pavadinimą: ";
            cin >> StrP[i];
            KAVA << StrP[i];
            cout << endl;

            cout << "Įveskite " << i + 1 << " kavos rušį: ";
            cin >> StrR[i];
            KAVA << " " << StrR[i] << " ";
            cout << endl;

            cout << "Įveskite " << i + 1 << " kavos gamintoją: ";
            cin >> StrG[i];
            KAVA << StrG[i] << " ";
            cout << endl;

            cout << "Įveskite "<< i+1 << " kavos kainą: ";
            cin >> doubleK[i];
            KAVA << doubleK[i] << " ";
            cout <<  endl;

            cout << "Įveskite "<< i+1 << " kavos svorį: ";
            cin >> doubleS[i];
            KAVA << doubleS[i];
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
        fstream KAVA("kava.txt");
        for (int i = 0; i <= n; i++)
        {
            cout << StrPavadinimas << "\t" << StrRusis << "\t" << StrGamintojas << "\t" << doubleKaina << "\t" << doubleSvoris;
        }
        KAVA.close();
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

};

class KavosSarasas
{
private:
    int n;
    Kava K[CHARCOUNT];
public:

    KavosSarasas(string vardas)

    {
        n = 0;
        string StrP, StrR, StrG;
        int doubleK, doubleS;
        fstream f(vardas);
        if (f.fail())
        {
            cout << "Nera failo\n";

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
    }
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
    Kava Ka;
    fstream KAVA;
    
    KAVA.open("kava.txt", ios::in);
    if (KAVA.fail())
    {
        cout << "Įveskite kelias skirtingas kavas norite įtraukti į sarašą: ";
        cin >> n;
        cout << endl;
        
        KAVA.open("kava.txt", ios::out);
        Ka.SukurtiDuomenis(n);
        KAVA.close();
        KAVA.clear();
        KAVA.open("kava.txt", ios::in);
         
        Ka.atspauzdintiFaila(n);

    }

    else
    {
     KavosSarasas KavosSarasas("kava.txt");
     KAVA.close();
     KAVA.clear();
     KavosSarasas.BendrasVidurkis();
    }

}