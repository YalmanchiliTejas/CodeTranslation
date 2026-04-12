#include <bits/stdc++.h>

#define debug(x) cerr << #x << ": " << x << endl
#define debugArray(x, n)                                                       \
    for(long long hoge = 0; (hoge) < (n); ++(hoge))                            \
    cerr << #x << "[" << hoge << "]: " << x[hoge] << endl
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
const ll INF = LLONG_MAX / 2;
const ll MOD = 1e9 + 7;

ll dfs(ll N, ll X) {
    ll total = (1ll << (N + 2)) - 3;
    // debug(X);
    if(X == 0)
        return 0;
    if(X == total)
        return (1ll << (N + 1)) - 1;
    if(N == 0)
        return 1;
    if(total > 2 * X) {
        return dfs(N - 1, X - 1);
    }
    return (1ll << N) + dfs(N - 1, X - ((1ll << (N + 1)) - 1));
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, X;
    cin >> N >> X;
    cout << dfs(N, X) << endl;
    return 0;
}
