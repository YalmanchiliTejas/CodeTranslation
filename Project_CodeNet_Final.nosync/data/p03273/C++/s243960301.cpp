/**
*    created: 24.06.2020 12:52:49
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pcnt(bit) __builtin_popcount(bit)
#define mod 1000000007
#define pi acos(-1.0)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    vector<vector<char>> mp;
    rep(i,h) {
        bool ok = false;
        vector<char> tmp(w);
        rep(j,w) {
            cin >> tmp[j];
        }
        rep(j,w) if (tmp[j] == '#') ok = true;
        if (ok) mp.push_back(tmp);
    }
    h = mp.size();
    vector<bool> out(w);
    rep(i,w) {
        bool yes = false;
        rep(j,h) if (mp[j][i] == '#') yes = true;
        if (yes) out[i] = true;
        else out[i] = false;
    }
    rep(i,h) {
        rep(j,w) if (out[j]) cout << mp[i][j];
        cout << endl;
    }
    return 0;
}