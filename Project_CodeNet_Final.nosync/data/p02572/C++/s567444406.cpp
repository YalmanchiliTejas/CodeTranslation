#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int n;
ll a[200000];
ll b[200001];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i + 1] = b[i] + a[i];
        b[i + 1] %= MOD;
    }
    ll ans = 0;
    for (int i = n - 1; i >= 1; --i) {
        ans += (a[i] * b[i]) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}