// RalfsTestfeld.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "RalfsTestfeldDefNSubfunc.h" // Einbinden der Unterfunktionen 

using namespace std; // Dann muss es nicht mehr std::cout heißen, sondern es kann auch nur cout verwendet werden 


class Testclass
{
public:
    Testclass() {}; // Leerer Konstruktor -> benötigt jetzt die geschweiften Klammern, sonst gibt's nen Fehler
    // Testclass(){ cout << "Konstruktor aufgerufen\n";}; // Konstruktor mit Textausgabe
    // ~Testclass(); // Dekonstruktor
    int var1 = 3;
    const int GetWert(); // Zugriffsfunktion ohne Wertänderung
    void SetWert(int Wert); // Zugriffsfunktion mit Wertänderung
    
private:
    int var2 = 7; // auf den Wert kann somit nicht direkt zugegriffen werden!
};

const int Testclass::GetWert()
{
    // cout << "(Der Wert im Speicher wird abgerufen.)\n";
    return var2;
}

void Testclass::SetWert(int Wert)
{
    var2 = Wert;
    // cout << "(Wert im Speicher wurde gesetzt.)\n";
}


//-------------------------------------------------------------------
class Oberklasse : public Testclass// Oberklasse soll alles von Testclass erben
{
public:
    // Oberklasse(); // Konstruktor
    // ~Oberklasse(); // Destruktor
    int Ovar1 = 17;
    const int ReadWert(); // Zugriffsfunktion
    void NewWert(int Owert); // Zugriffsfunktion zur Wertänderung
private:
    int Ovar2 = 20;
};

const int Oberklasse::ReadWert()
{
    // cout << "(Der Wert im Speicher wird abgerufen.)\n";
    return Ovar2;
}

void Oberklasse::NewWert(int Owert)
{
    Ovar2 = Owert;
    // cout << "(Wert im Speicher wurde gesetzt.)\n";
}


//-----------------------------------------------------------------
int main()
{
    Testclass tester;
    cout << "Wert in tester.var2 ist: ";
    cout << tester.GetWert() << "\n"; // Hier die Klammern nicht vergessen, sonst gibt es ne Fehlermeldung
    cout << "Setzen des Wertes von tester.var2 auf 5 durch Zugriffsfunktion.\n";
    tester.SetWert(5);
    cout << "Wert in tester.var2 ist: ";
    cout << tester.GetWert()  << "\n"; // Hier die Klammern nicht vergessen, sonst gibt es ne Fehlermeldung
        
    cout << "wert von tester.var1: ";
    cout << tester.var1 << "\n";
//  ------------------------------------------
    Oberklasse Otest;
    cout << "Wert in Otest.Ovar2 ist: ";
    cout << Otest.ReadWert() << "\n"; // Hier die Klammern nicht vergessen, sonst gibt es ne Fehlermeldung
    cout << "Wert in Otest.var2 ist: ";
    cout << Otest.GetWert() << "\n"; // Der Standardwert für var2 wird ausgegeben, da dieser beim initialisieren/vererben mit diesen Werten übernommen wird!
    // Vergleich mit dem aktuellen Wert im tester Object
    cout << "Wert in tester.var2 ist: ";
    cout << tester.GetWert() << "\n"; // Hier die Klammern nicht vergessen, sonst gibt es ne Fehlermeldung

    // Verändern des Wertes in Otest
    cout << "Setzen des Wertes von Otest.Ovar2 auf 42 durch Zugriffsfunktion.\n";
    Otest.NewWert(42);
    cout << "Setzen des Wertes von Otest.var2 auf 21 durch Zugriffsfunktion.\n";
    Otest.SetWert(21);
    cout << "Wert in Otest.Ovar2 ist: ";
    cout << Otest.ReadWert() << "\n"; // Der Standardwert für var2 wird ausgegeben, da dieser beim initialisieren/vererben mit diesen Werten übernommen wird!
    cout << "Wert in Otest.var2 ist: ";
    cout << Otest.GetWert() << "\n"; // Der Standardwert für var2 wird ausgegeben, da dieser beim initialisieren/vererben mit diesen Werten übernommen wird!


    // Unterfunktion einbinden

    int Ausgabe = WertBerechnen(15, 17);
    cout << "Die Unterfunktion berechnet: "<< Ausgabe << "\n" ;

    double AusgabeDouble = WertBerechnen(15.0f, 17.0f);
    cout << "Die Unterfunktion berechnet: " << AusgabeDouble << "\n";



//  ---------------------------------------------
    cout << "Programm ist fertig...\n";
    return 0;
}

// Programm ausführen: STRG+F5 oder "Debuggen" > Menü "Ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.