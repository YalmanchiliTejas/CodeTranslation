#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

const ll mod = 1000000007;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    ll ans = 0;
    ll total = 0;
    rep(i, N) total += A[i];
    rep(i, N) {
        total -= A[i];
        ans += (A[i] * (total % mod)) % mod;
        ans %= mod;
    }

    cout << ans << endl;
}
