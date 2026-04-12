#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using st = string;
using P = pair<int, int>;
#define mrep(i, m, n) for(int i = m; i < n; i++)
#define rep(i, n) mrep(i, 0, n)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

const int mod = (int) (1e9 + 7);

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a.at(i);
    vector<ll> b(n + 1, 0);
    rep(i, n){
        b.at(i + 1) = b.at(i) + a.at(i);
    }
    ll ans = 0;
    rep(i, n){
        ll sum = (b.at(n) - b.at(i + 1)) % mod; // A[i] + ... + A[N - 1] = B[N] - B[i]
        ans += (a.at(i) * sum) % mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}