#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << ": " << x << endl;
#define ll long long

int main() {
    char c;
    cin >> c;
    string s = "aeiou";
    if (s.find(c) != string::npos) {
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }

    return 0;
}