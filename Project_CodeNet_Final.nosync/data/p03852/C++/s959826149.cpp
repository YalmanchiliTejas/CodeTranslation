#include <iostream>
using namespace std;

int main()
{
    char c;
    cin >> c;
    string s = "consonant";
    if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') s = "vowel";
    cout << s << endl;

    return 0;
}