#include <iostream>
#include <string>
using namespace std;
 
int main() {
    string s;
    cin >> s;
    if( s[0] == 'a') cout << "vowel" << endl;
    else if( s[0] == 'i') cout << "vowel" << endl;
    else if( s[0] == 'u') cout << "vowel" << endl;
    else if( s[0] == 'e') cout << "vowel" << endl;
    else if( s[0] == 'o') cout << "vowel" << endl;
    else cout << "consonant" << endl;
    return 0;
}