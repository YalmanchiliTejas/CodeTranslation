#include <iostream>

using namespace std;

int main()
{
    char c; cin >> c;
    if(c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'i') cout << "vowel";
    else cout << "consonant";

    return 0;
}
