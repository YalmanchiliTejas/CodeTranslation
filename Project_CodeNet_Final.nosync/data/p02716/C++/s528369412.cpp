#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define FORR(i, n) for(ll i = (ll)n - 1LL; i >= 0LL; i--)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template <typename T> using V = vector<T>;
constexpr int Mod = 998244353;
constexpr int mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;
template <typename T> constexpr bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

void solve0(ll n) {
    V<ll> a(n);
    V<ll> sum0(n), sum1(n + 2);
    rep(i, n) {
        cin >> a[i];
        (i & 1 ? sum1 : sum0)[i] = a[i];
    }
    rep(i, n - 1) sum0[i + 1] += sum0[i];
    FORR(i, n - 1) sum1[i] += sum1[i + 1];

    ll ans = sum1[0];
    for(int i = 0; i < n; i += 2) {
        chmax(ans, sum0[i] + sum1[i + 2]);
    }
    cout << ans << endl;
    exit(0);
}

void solve1(ll n) {
    ll sum = 0;
    V<ll> a(n + 1);
    FOR(i, 1, n + 1) cin >> a[i], sum += a[i];
    V<V<ll>> dp(n + 1, V<ll>(2, inf));
    dp[0][0] = 0;
    FOR(i, 1, n + 1) {
        if(i & 1) {
            chmin(dp[i][1], dp[i - 1][0] + a[i]);
            if(i > 1) chmin(dp[i][1], dp[i - 2][1] + a[i]);
        } else {
            chmin(dp[i][0], min(dp[i - 1][0], dp[i - 2][0]) + a[i]);
            chmin(dp[i][1], min(dp[i - 1][1], dp[i - 2][1]) + a[i]);
        }
    }
    cout << sum - min(dp[n - 1][1], dp[n][1]) << endl;

    exit(0);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll n;
    cin >> n;
    if(n % 2 == 0) solve0(n);
    solve1(n);

    return 0;
}