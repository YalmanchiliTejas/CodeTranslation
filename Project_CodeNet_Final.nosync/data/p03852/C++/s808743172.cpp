#include <bits/stdc++.h>
using namespace std;

int main() {
    string c, ans;
    cin >> c;

    if (c == "a" || c == "e" || c == "i" || c == "o" || c == "u") ans = "vowel";
    else ans = "consonant";

    cout << ans << endl;
}