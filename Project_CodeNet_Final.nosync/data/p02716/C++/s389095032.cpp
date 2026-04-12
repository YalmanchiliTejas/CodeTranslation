#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define all(v) v.begin(), v.end()
const ll INF = 9999999999999999;
const ll MOD = 1000000007;
const ll MAX_N = 500010;
ll a, b, c, d, e, f, p, t, x, y, z, q, m, n, r, h, k, w, l, ans;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    vl A;
    ll dp[n][4]; //どこまで見たか・i番目まで見たときにi-(使った数)*2+2
    rep(i, n) {
        cin >> a;
        A.push_back(a);
    }

    rep(i, n) {
        if(i == 0) {
            dp[0][0] = A[0];
            dp[0][1] = -INF;
            dp[0][2] = -INF;
        } else {
            if(i == 1)
                dp[i][0] = -INF;
            else
                dp[i][0] = dp[i - 2][0] + A[i];
            if(i == 1)
                dp[i][1] = A[i];
            else
                dp[i][1] = dp[i - 2][1] + A[i];
            if(i > 2)
                dp[i][1] = max(dp[i - 3][0] + A[i], dp[i][1]);
            if(i == 1)
                dp[i][2] = -INF;
            else if(i == 2)
                dp[i][2] = A[i];
            else
                dp[i][2] = dp[i - 2][2] + A[i];
            if(i > 2)
                dp[i][2] = max(dp[i - 3][1] + A[i], dp[i][2]);
            if(i > 3)
                dp[i][2] = max(dp[i - 4][0] + A[i], dp[i][2]);
        }
    }

    if(n % 2 == 0)
        ans = max(dp[n - 2][0], dp[n - 1][1]);
    else
        ans = max({dp[n - 3][0], dp[n - 2][1], dp[n - 1][2]});

    cout << ans << endl;
}
