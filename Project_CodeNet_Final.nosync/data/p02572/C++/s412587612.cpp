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
const ll mod = 1e9 + 7;

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
    int n;
    cin >> n;
    ll a[n];
    for (i = 0; i < n; i++) cin >> a[i];
    ll s = 0;
    for (i = 0; i < n; i++) s += a[i];
    s %= mod;
    s = s * s % mod;
    for (i = 0; i < n; i++) {
        s += mod - a[i] * a[i] % mod;
        s %= mod;
    }
    cout << s * (mod + 1) / 2 % mod << endl;
}