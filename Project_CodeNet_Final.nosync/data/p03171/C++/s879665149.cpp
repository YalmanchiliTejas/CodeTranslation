#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}

ll dp[3000][3000];
bool vis[3000][3000];
ll a[3000];
int n;

ll solve(int l, int r) {
    if (vis[l][r])
        return dp[l][r];
    vis[l][r] = true;
    bool taro = (n - 1 - (r - l)) % 2 == 0;
    ll ret;
    if (taro) {
        if (l == r)
            ret = a[l];
        else {
            ret = -INF;
            chmax(ret, solve(l + 1, r) + a[l]);
            chmax(ret, solve(l, r - 1) + a[r]);
        }
    } else {
        if (l == r)
            ret = -a[l];
        else {
            ret = INF;
            chmin(ret, solve(l + 1, r) - a[l]);
            chmin(ret, solve(l, r - 1) - a[r]);
        }
    }
    return dp[l][r] = ret;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << solve(0, n - 1) << "\n";
    return 0;
}