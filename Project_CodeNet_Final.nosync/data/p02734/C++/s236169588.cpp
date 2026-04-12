#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<ll, ll> P;
using VP = vector<P>;
using VVP = vector<VP>;
using VI = vector<ll>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
const int inf = 1e9 + 7;
const ll INF = 1LL << 61;
const ll mod = 998244353;

template <class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int i, j;
    ll n, s;
    cin >> n >> s;
    ll a[n];
    for (i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    VI v(3030, 0);
    for (i = 0; i < n; i++) {
        v[0]++;
        for (j = 3029; j >= a[i]; j--) {
            v[j] += v[j - a[i]];
            v[j] %= mod;
        }
        ans += v[s];
        ans %= mod;
    }
    cout << ans << endl;
}