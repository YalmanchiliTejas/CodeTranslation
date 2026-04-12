#include <bits/stdc++.h>
using namespace std;

int main() {
    char c;
    string res;
    cin >> c;
    if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') res = "vowel";
    else res = "consonant";
    cout << res << endl;
}
