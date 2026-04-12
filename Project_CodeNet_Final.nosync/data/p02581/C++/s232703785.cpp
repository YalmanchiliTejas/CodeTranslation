
#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef int ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;

#define rep(a,n) for(ll a = 0;a < n;a++)

static const ll INF = 1e15;
static const ll mod = 1e9+7;

template<typename T>
static inline void chmin(T& ref, const T  value) {
    if (ref > value) ref = value;
}

template<typename T>
static inline void chmax(T& ref, const T value) {
    if (ref < value) ref = value;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> vs(3 * n);
    rep(i, 3 * n) {
        cin >> vs[i];
        vs[i]--;
    }
    vector<vector<ll>> dp(n, vector<ll>(n, -3*n));
    vector<ll> dpMax(n, -3 * n);
    ll cMax = 0;
    ll threes = 0;
    dp[vs[0]][vs[1]] = 0;
    dp[vs[1]][vs[0]] = 0;
    dpMax[vs[0]] = 0;
    dpMax[vs[1]] = 0;
    vector<t3> updates;
    updates.reserve(n* n);
    for (int i = 0; i < n - 1; i++) {
        updates.clear();
        const ll* buffer = &vs[3*i+2];
        //3枚同じ
        if (buffer[0] == buffer[1] and buffer[1] == buffer[2]) {
            threes++;
            continue;
        }
        //2枚同じ
        if (buffer[0] == buffer[1]) {
            ll p = buffer[0];
            ll k = buffer[2];
            for (int j = 0; j < n; j++) {
                updates.emplace_back(j, k, dp[p][j] + 1);
                updates.emplace_back(j, k, dp[j][p] + 1);
            }
        }
        else if (buffer[1] == buffer[2]) {
            ll k = buffer[0];
            ll p = buffer[2];
            for (int j = 0; j < n; j++) {
                updates.emplace_back(j, k, dp[p][j] + 1);
                updates.emplace_back(j, k, dp[j][p] + 1);
            }
        }
        else if (buffer[0] == buffer[2]) {
            ll k = buffer[1];
            ll p = buffer[2];
            for (int j = 0; j < n; j++) {
                updates.emplace_back(j, k, dp[p][j] + 1);
                updates.emplace_back(j, k, dp[j][p] + 1);
            }
        }
        //3枚ばらばらでカウント
        ll p = buffer[0];
        ll k = buffer[1];
        ll l = buffer[2];
        updates.emplace_back(k, l, dp[p][p] + 1);
        updates.emplace_back(p, l, dp[k][k] + 1);
        updates.emplace_back(p, k, dp[l][l] + 1);
        rep(j, 3) {
            rep(a, j) {
                ll p = buffer[a];
                ll k = buffer[j];
                updates.emplace_back(p, k, cMax);
            }
        }
        rep(j, 3) {
            ll p = buffer[j];
            rep(k, n) {
                updates.emplace_back(k, p, dpMax[k]);
            }
        }
        for (auto t : updates) {
            ll j, k, v;
            tie(j, k, v) = t;
            chmax(dp[j][k], v);
            chmax(dp[k][j], v);
            chmax(dpMax[j], v);
            chmax(dpMax[k], v);
            chmax(cMax, v);
        }
    }
    ll u = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == vs[3 * n - 1] && i == j) {
                chmax(u, dp[i][i] + 1);
            }
            else {
                chmax(u, dp[i][j]);
            }
        }
    }
    cout << u + threes << endl;
    return 0;
}
