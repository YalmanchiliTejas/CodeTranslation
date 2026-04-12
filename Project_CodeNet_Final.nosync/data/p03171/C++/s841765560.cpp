#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr int mod = 1e9 + 7;

template <class T> inline bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <class T> inline bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int n;
ll a[3000], dp[3000][3000];
bool fin[3000][3000];

ll f(int l, int r) {
    if(l > r) return 0;
    if(!fin[l][r]) {
        fin[l][r] = true;
        if(r + l + n & 1)
            dp[l][r] = max(a[l] + f(l + 1, r), f(l, r - 1) + a[r]);
        else
            dp[l][r] = min(f(l + 1, r) - a[l], f(l, r - 1) - a[r]);
    }
    return dp[l][r];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    rep(i, n) cin >> a[i];

    cout << f(0, n - 1) << endl;

    return 0;
}