#include <iostream>

#include "RalfsTestfeldDefNSubfunc.h" // Einbinden des Headers 

int WertBerechnen(int Wert1, int Wert2)
{
	int Ausgabewert = Wert1 + Wert2;
	return Ausgabewert;
}


double WertBerechnen(double Wert1, double Wert2) //  �berladen der Funktion: Funktion wird nach Struktur der �bergebenen Variablen ausgew�hlt. 
{
	double Ausgabewert = (Wert1 + Wert2) * 100;
	return Ausgabewert;
}