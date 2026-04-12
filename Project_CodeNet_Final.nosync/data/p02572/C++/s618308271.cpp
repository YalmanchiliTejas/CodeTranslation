#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define P pair<ll, ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr ll mod = 1000000007;
constexpr ll INF = (1ll << 60);
constexpr double pi = 3.14159265358979323846;
template <typename T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    ll n;
    cin >> n;

    // sum:和の二乗　sumpow:二乗の和
    ll sum = 0, sumpow = 0;
    rep(i, n) {
        ll a;
        cin >> a;
        sum += a;
        sumpow += (a * a) % mod;

        sum %= mod;
        sumpow %= mod;
    }

    sum = (sum * sum) % mod;

    cout << (((sum - sumpow + mod) % mod) * (mod + 1) / 2) % mod << "\n";
    return 0;
}