#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
using namespace std;

int main() {
    string s;
    cin >> s;

    bool a = false, b = false;
    rep(i, 0, 3) {
        if (s[i] == 'A') a = true;
        if (s[i] == 'B') b = true;
    }

    if (a && b) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}