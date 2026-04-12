#include <bits/stdc++.h>
using namespace std;
 
int main() {
    char c;
    cin >> c;
    string vowel = "aeiuo";
    if (vowel.find(c) != string::npos) cout << "vowel" << endl;
    else cout << "consonant" << endl;
}