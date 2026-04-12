#include<bits/stdc++.h>
using namespace std;

int main() {
    char c;
    cin >> c;
    string ans = "consonant";
    if ("aeiou"s.find(c) != string::npos) ans = "vowel";
    cout << ans << endl;
}
