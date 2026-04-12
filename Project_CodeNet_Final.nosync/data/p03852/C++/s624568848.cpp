#include <bits/stdc++.h>
using namespace std;

int main() {
    char c;
    cin >> c;
    
    set<char> boin = {'a', 'i', 'u', 'e', 'o'};
    if (boin.count(c)) {
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }
}