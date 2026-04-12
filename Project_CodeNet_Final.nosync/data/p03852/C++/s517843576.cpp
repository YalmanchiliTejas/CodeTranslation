#include <bits/stdc++.h>

using namespace std;

int main() {
    string src = "aiueo";
    char c;
    cin >> c;
    cout << (src.find(c) != string::npos ? "vowel" : "consonant") << endl;

    return 0;
}