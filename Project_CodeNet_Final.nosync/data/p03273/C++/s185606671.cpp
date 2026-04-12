#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

int x[100];

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> a;
    rep(i, h) {
        bool ok = true;
        string s;
        cin >> s;
        rep(i, w) {
            if(s[i] != '.') ok = false;
        }
        if(!ok) a.push_back(s);
    }
    int n = a.size();
    rep(j, w) {
        bool ok = true;
        rep(i, n) {
            if(a[i][j] != '.') ok = false;
        }
        if(ok) x[j]++;
    }
    rep(i, n) {
        rep(j, w) {
            if(x[j] != 1) cout << a[i][j];
            else continue;
        }
        cout << endl;
    }
    return 0;
}