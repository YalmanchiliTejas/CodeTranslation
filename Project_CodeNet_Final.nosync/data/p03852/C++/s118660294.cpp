#include <bits/stdc++.h>
using namespace std;

int main(void) {
    char a;
    cin >> a;
    switch (a) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            cout << "vowel\n";
            break;
        default:
            cout << "consonant\n";
            break;
    }
    return 0;
}
