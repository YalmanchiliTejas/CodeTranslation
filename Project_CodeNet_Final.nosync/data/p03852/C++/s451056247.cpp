#include <iostream>

using namespace std;

int main()
{
    char c;
    cin >> c;

    if ((int)c >=97 && (int) c <= 122)

    if ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' )

    cout << "vowel";

    else
        cout << "consonant";
    return 0;
}