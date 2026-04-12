#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ch(26, INT_MAX);
    rep(i, n) {
        string str;
        cin >> str;
        vector<int> temp(26, 0);
        rep(j, str.length()) temp.at(str.at(j) - 'a')++;
        rep(j, 26) ch.at(j) = min(ch.at(j), temp.at(j));
    }
    string ans = "";
    rep(i, 26) rep(j, ch.at(i)) ans += 'a' + i;
    cout << ans << endl;
}