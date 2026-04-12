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
vector<ll> sum;
void pre_process(vector<ll> &a, vector<ll> &s) {  //累積和のvector
    ll n = (ll)a.size();
    s.assign(n + 1, 0);
    for (ll i = 0; i < n; i++) {
        s[i + 1] = (s[i] + a[i]) % mod;
        s[i + 1] %= mod;
    }
}
ll query(ll i, ll j, vector<ll> &s) {  //区間[i,j]の和
    return (s[j] - s[i]);
}

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll suma = 0;
    pre_process(a, sum);
    rep(i, n - 1) {
        suma += ((a[i] * (sum[n] - sum[i + 1])) % mod);
        suma %= mod;
    }

    /*ll sumb = 0;
    rep(i, n - 1) {
        for (ll j = i + 1; j < n; j++) sumb += a[i] * a[j];
    }
    cout << sumb << endl;*/

    cout << (suma + mod) % mod << "\n";
    return 0;
}