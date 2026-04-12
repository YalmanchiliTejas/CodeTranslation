#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define for(i, a, b) for(ll (i)=a;(i)<(b);++(i))
#define rep(i, n)    for(i, 0, n)
#define sz(x)        ((ll)(x).size())
#define inf          1<<25

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int main() {
    int n;
    cin >> n;
    
    string v[n];
    rep(i, n) cin >> v[i];
    
    ll num[n][26] = {};
    rep(i, n) rep(j, sz(v[i])) num[i][(char)v[i][j] - 'a']++;
    
    string ans = "";
    rep(j, 26) { 
        ll k = inf;
        rep(i, n) k = min(k, num[i][j]);
        rep(i, k) ans += 'a' + j;
    }
    cout << ans << endl;
    
    return 0;
}