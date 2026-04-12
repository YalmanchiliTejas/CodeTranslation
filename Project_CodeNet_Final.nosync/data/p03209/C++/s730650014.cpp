#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
// using namespace atcoder;

ll dfs(ll L, ll X, vector<ll>& c, vector<ll>& p) {
    if (L == 0) {
        return 1;
    }
    if (X == 0) {
        return 0;
    }
    if (X == c[L] / 2) {
        return p[L] - p[L] / 2;
    }
    if (X == c[L] - 1) {
        return p[L];
    }
    if (X < c[L] / 2) {
        return dfs(L - 1, X - 1, c, p);
    }
    else {
        ll res = dfs(L - 1, X - c[L] / 2 - 1, c, p);
        res += 1 + p[L] / 2;
        return res;
    }
}

void Main()
{
    ll n, X;
    cin >> n >> X;
    X--;

    vector<ll> c(n + 1);
    vector<ll> p(n + 1);
    c[0] = 1;
    repi(i, n + 1) c[i] = c[i - 1] * 2 + 3;
    p[0] = 1;
    repi(i, n + 1) p[i] = p[i - 1] * 2 + 1;

    ll res = dfs(n, X, c, p);
    put(res);
}
signed main(){ Main();return 0;}