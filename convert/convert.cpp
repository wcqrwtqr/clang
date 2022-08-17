#include <fstream>
#include <iostream>
#include <limits>
using namespace std;

/*
 * Date: 17 Aug 2022
 * This script I made to quickly convert the flow rates from meter, letter or
 * gallon to bbl which I use for my work
 */

// Delclaration of functions
double leterhour(int);
double metercubehour(int);
double metercubeday(int);
double gallonpermin(int);
void checkcin();
void checkvalue(int x, double (*func)(int)); // Check the value if its too high and print a comment

int main() {
  int amount;
  char ch;

  do {
    system("clear");
    cout << "\n\n\tSelect option";
    cout << "\n\n\t01. Leter per min";
    cout << "\n\n\t02. Meter^3 per day";
    cout << "\n\n\t03. Meter^3 per hour";
    cout << "\n\n\t04. Gallon per min";
    cout << "\n\n\t05. EXIT";
    cout << "\n\n\tSelect your option (1-4) ";
    cin >> ch;
    system("clear");
    switch (ch) {
    // ==========
    case '1':
      cout << "\n\n\tEnter the amount in L/min: ";
      cin >> amount;
      checkcin();
      checkvalue(amount, &leterhour);
      cout << "\n\t" << leterhour(amount) << " bbl/d";
      break;
    // ==========
    case '2':
      cout << "\n\n\tEnter the amount in m^3/d: ";
      cin >> amount;
      checkcin();
      checkvalue(amount, &metercubeday);
      cout << "\n\t" << metercubeday(amount) << " bbl/d";
      break;
    // ==========
    case '3':
      cout << "\n\n\tEnter the amount in m^3/h: ";
      cin >> amount;
      checkcin();
      checkvalue(amount, &metercubehour);
      cout << "\n\t" << metercubehour(amount) << " bbl/d";
      break;
    // ==========
    case '4':
      cout << "\n\n\tEnter the amount in gpm: ";
      cin >> amount;
      checkcin();
      checkvalue(amount, &gallonpermin);
      cout << "\n\t" << gallonpermin(amount) << " bbl/d";
      break;
    // ==========
    case '5':
      cout << "\n\n\tThanks for using my app\n";
      break;
    // ==========
    default:
      cout << "\n\tPlease choose the correct option number\n";
    }
    cin.ignore();
    cin.get();
  } while (ch != '5');

  return 0;
}

double leterhour(int x) { return x * 9.054144; }
double metercubehour(int x) { return x * 150.9096; }
double metercubeday(int x) { return x * 6.2876; }
double gallonpermin(int x) { return x * 34.28571312; }

// This function pass the amount to the function and check if the value is too high
void checkvalue(int x, double (*func)(int)) {
  if (func(x) > 20000) {
    cout << "\n\t"
         << "The value is too big!!!";
  }
}

// This function check if the input is good or not and clear the cin to avoid crashing
void checkcin() {
  while (!cin.good()) {
    cin.clear();
    cin.ignore();
  }
}
