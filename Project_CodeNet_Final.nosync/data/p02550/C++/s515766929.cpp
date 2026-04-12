#include<bits/stdc++.h>

using namespace std;
using ll = long long int;
using lc = complex<double>;

int main(void) {
    constexpr ll MOD = 998244353;
    constexpr double PI = acos(-1);
    cout << fixed << setprecision(32);
    cin.tie(0); ios::sync_with_stdio(false);

    ll n, x, m;
    cin >> n >> x >> m;
    vector<vector<tuple<ll,ll>>> tbl(m, vector<tuple<ll,ll>>(55));
    for(ll i=0; i<m; i++) {
        ll t = (i*i)%m;
        tbl[i][0] = {t, i%m};
    }

    for(ll k=1; k<50; k++) {
        for(ll i=0; i<m; i++) {
            auto [x, y] = tbl[i][k-1];
            auto [z, w] = tbl[x][k-1];
            tbl[i][k] = {z, w+y};
        }
    }

    ll res = 0, u = x;
    for(ll k=50; ; k--) {
        if(!((n>>k)&1)) {
            if(k==0) break;
            continue;
        }
        auto [x, y] = tbl[u][k];
        res += y;
        u = x;
        if(!k) break;
    }
    cout << res << endl;
}