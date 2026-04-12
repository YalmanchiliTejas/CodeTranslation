#include <iostream>
using namespace std;
int main()
{
    char c;
    cin >> c;
    c = tolower(c);
    if (c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u')
        cout << "vowel\n";
    else
        cout << "consonant\n";
    return 0;
}


