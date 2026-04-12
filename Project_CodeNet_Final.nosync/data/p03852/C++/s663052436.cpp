#include<iostream>
using namespace std;

int main() {
    char c; cin >> c;
    string ans = "consonant";
    for (char ch: "aiueo") {
        if (ch == c) ans = "vowel";
    }
    cout << ans << endl;
}