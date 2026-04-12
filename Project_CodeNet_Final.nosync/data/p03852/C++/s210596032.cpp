#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
    char ch;
    cin >> ch;
    switch(ch) {
        case 'a':
        case 'i':
        case 'u':
        case 'e':
        case 'o':
            cout << "vowel" << endl;
            break;
        default:
            cout << "consonant" << endl;
            break;
    }
}