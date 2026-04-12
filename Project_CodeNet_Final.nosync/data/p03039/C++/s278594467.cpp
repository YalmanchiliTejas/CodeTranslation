#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define REPR(i,n) for (ll i = n-1; i >= 0; --i)
#define FOR(i,m,n) for (ll i = m; i < n; ++i)
#define FORR(i,m,n) for (ll i = n-1; i >= m; --i)
#define FORE(x,xs) for (const auto& x : xs)
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()

const int MOD = 1e9+7;

ll N, M, K;

int pow(ll n, ll k, int mod) {
    ll res = 1;
    while (k > 0) {
        if (k&1) res = res*n%mod;
        n = n*n%mod;
        k >>= 1;
    }
    return res;
}

int inv(int n) {
    return pow(n, MOD-2, MOD);
}

int comb(int n, int k) {
    ll res = 1;
    FOR (i, 1, n+1) res = res*i%MOD;
    FOR (i, 1, k+1) res = res*inv(i)%MOD;
    FOR (i, 1, n-k+1) res = res*inv(i)%MOD;
    return res;
}

ll query(int w, int h) {
    ll res = 0;
    ll c = comb(N*M-2, K-2);
    FOR (d, 1, w) {
        res += (w-d) * d % MOD * h % MOD * h % MOD * c;
        res %= MOD;
    }
    return res;
}

int solve() {
    return (query(N, M) + query(M, N)) % MOD;
}

int main() {
    cin >> N >> M >> K;
    cout << solve() << endl;
}