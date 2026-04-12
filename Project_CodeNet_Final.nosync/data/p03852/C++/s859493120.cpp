#include <bits/stdc++.h>
using namespace std;

int main() {
    char c;
    cin >> c;

    bool flag = false;
    if (c == 'a') flag = true;
    if (c == 'e') flag = true;
    if (c == 'i') flag = true;
    if (c == 'o') flag = true;
    if (c == 'u') flag = true;

    if (flag) cout << "vowel" << endl;
    else cout << "consonant" << endl;

    return 0;
}