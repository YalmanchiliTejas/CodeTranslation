#include <iostream>

using namespace std;

int main()
{
    char c;
    cin >> c;
    string s = "consonant";
    if( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ) s = "vowel";
    cout << s << '\n';
    return 0;
}
