#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

int main() {
    char c;
    cin >> c;

    switch (c) {
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

    return 0;
}