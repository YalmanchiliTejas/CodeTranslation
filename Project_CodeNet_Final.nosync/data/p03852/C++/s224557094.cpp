#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    char s[5];
    cin >> s;
    if (s[0] == 'a' || s[0] == 'i' || s[0] == 'u' || s[0] == 'e' || s[0] == 'o')
    {
        cout << "vowel" << endl;
    }
    else
        cout << "consonant" << endl;
    return 0;
}