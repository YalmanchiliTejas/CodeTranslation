#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main() {
    int n; cin >> n;
    vector<int> seki(26, 50);
    rep(i, n) {
        string s; cin >> s; int sz = s.size();
        vector<int> tmp(26, 0);
        rep(i, sz) tmp[s[i]-'a']++;
        rep(i, 26) seki[i] = min(seki[i], tmp[i]);
    }
    rep(i, 26) {
        char alp = 'a' + i;
        rep(j, seki[i]) {
            cout << alp;
        }
    }puts("");
}
