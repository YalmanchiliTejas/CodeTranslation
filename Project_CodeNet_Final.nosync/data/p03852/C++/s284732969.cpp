#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    char c;
    cin >> c;

    bool vow = false;
    switch (c) {
        case 'a' :
        case 'e' : 
        case 'i' :
        case 'o' :
        case 'u' : vow = true; break;
        default : break;
    }

    cout << (vow ? "vowel" : "consonant") << endl;

    return 0;
}
