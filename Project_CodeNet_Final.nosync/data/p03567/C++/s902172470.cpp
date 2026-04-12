#include "bits/stdc++.h"
using namespace std;

int main() {
    string s;
    cin >> s;
    bool T = false;
    for (int i = 0; i < s.length()-1; i++) {
        if (s[i]=='A' && s[i+1]=='C') {
            T = true;
            break;
        }
        if (T) break;
    }
    if (T) cout << "Yes\n";
    else cout << "No\n";
}