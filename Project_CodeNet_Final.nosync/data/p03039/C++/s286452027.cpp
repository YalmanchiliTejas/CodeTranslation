#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rrep(i, st, n) for (int i = st; i < n; ++i)
using pii = pair<int, int>;
const int mod = 1e9 + 7;
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {1, -1, 0, 0, -1, 1, 1, -1};
#define ceil(a, b) a / b + !!(a % b)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
long power(long a,long b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}
ll calc(ll n, ll m, ll k) {
    ll sigma_comb;
    ll a = 1, b = 1, c = 1;
    rrep(i, 1, m * n - 2 + 1) {a *= i; a %= mod;}
    rrep(i, 1, m * n - k + 1) {b *= i; b %= mod;}
    rrep(i, 1, k - 2 + 1) {c *= i; c %= mod;}
    sigma_comb = a * power(b * c % mod, mod - 2) % mod;
    ll sigma_ij = 0;
    rep(d, n) {sigma_ij += d * (n - d) * (m * m); sigma_ij %= mod;}
    return sigma_comb * sigma_ij % mod;
}
int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n, m, k; cin >> n >> m >> k;
    ll ansx = calc(n, m, k), ansy = calc(m, n, k);
    cout << (ansx + ansy) % mod << endl;
}
