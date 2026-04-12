#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Welcome to my source code!

int main() {
    string s;
    cin >> s;
    int n = s.size();
    bool flag = false;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) flag = true;
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}