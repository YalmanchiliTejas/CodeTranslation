#include <iostream>
#include <string>
using namespace std;

int main(void) {
    const string vowel = "aeiou";
    char c;

    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> c;
    cout << (vowel.find(c) != string::npos? "vowel" : "consonant") << "\n"; 
    return 0;
}