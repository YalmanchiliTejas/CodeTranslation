#include <bits/stdc++.h>
using namespace std;

int main() {
    string S = "aeiou"s;
    char c;
    cin >> c;
    for ( size_t i = 0; i < S.size(); ++i ) {
        if ( S.at( i ) == c ) {
            cout << "vowel"s;
            return 0;
        }
    }
    cout << "consonant"s;
}