#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define endl '\n'
#define int long long

signed main() {
    string s;
    cin >> s;

    if(s[0] == s[1] && s[1] == s[2]) cout << "No" << endl;
    else cout << "Yes" << endl;
}