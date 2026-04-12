#include <iostream>
using namespace std;

int main()
{
    char stas[4];
    cin >> stas;
    bool IsS = false;
    IsS = stas[0] == stas[1] && stas[1] == stas[2];
    cout << (IsS ? "No" : "Yes") << endl;
}