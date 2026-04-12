#include <iostream>
using namespace std;

int main()
{
    char a;
    cin >> a;
    if (a == 'a' || a == 'e' || a == 'o' || a == 'i' || a == 'u') { cout << "vowel"; }
    else
        cout << "consonant";
}