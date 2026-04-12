#include <iostream>
using namespace std ;
int main ()
{
    string c ;
    cin >> c ;
    if (c == "a" || c == "e" || c == "i" || c == "o" || c == "u")
        cout << "vowel" ;
    else
        cout << "consonant";
}
