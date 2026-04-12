//
// Created by Hideaki Imamura on 2020-03-22.
//
# include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair <ll, ll> l_l;
typedef pair<int, int> i_i;

template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

# define EPS (1e-7)
# define INF (1e9)
# define PI (acos(-1))
const ll mod = 998244353;

inline ll take_mod(ll a) {
    return (a % mod + mod) % mod;
}

inline ll add(ll a, ll b) {
    return take_mod(a + b);
}

inline ll sub(ll a, ll b) {
    return take_mod(a - b);
}

inline ll mul(ll a, ll b) {
    return take_mod(a * b);
}

inline ll mod_pow(ll x, ll n) {
    ll res = 1LL;
    while (n > 0) {
        if (n & 1) res = mul(res, x);
        x = mul(x, x);
        n >>= 1;
    }
    return res;
}

ll mod_inv(ll x) {
    return mod_pow(x, mod - 2);
}

int N, S;
vector<int> A;

int main() {
    cin >> N >> S;
    A.resize(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    ll ans = 0;
    vector<vector<ll>> f(N + 1, vector<ll>(S + 1, 0));
    for (int i = 1; i <= N; ++i) {
        f[i][0] = add(f[i-1][0], 1);
        for (int j = 1; j <= min(A[i-1]-1, S); ++j) f[i][j] = f[i-1][j];
        //cout << A[i-1] << " " << S << endl;
        if (A[i-1] <= S) {
            f[i][A[i-1]] = add(1, add(f[i-1][0], f[i-1][A[i-1]]));
            for (int j = A[i-1] + 1; j <= S; ++j) f[i][j] = add(f[i-1][j], f[i-1][j - A[i-1]]);
        }
        ans = add(ans, f[i][S]);
    }
    cout << ans << endl;
    return 0;
}