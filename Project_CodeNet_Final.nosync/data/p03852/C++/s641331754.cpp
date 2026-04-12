#include<bits/stdc++.h>
using namespace std;

int main() {
    char c; cin >> c;
    string vowel = "aiueo";
    cout << (vowel.find(c) == string::npos ? "consonant" : "vowel") << endl;
}