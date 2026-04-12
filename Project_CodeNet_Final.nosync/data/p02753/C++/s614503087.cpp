#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    if (s[0] != s[1] || s[0] != s[2] || s[1] != s[2]) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}