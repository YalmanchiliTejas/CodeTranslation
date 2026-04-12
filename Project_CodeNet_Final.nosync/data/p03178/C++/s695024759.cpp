/// 2:59 PM 27/05/20
/// Author: t_bone_289 (An Immature Programmer.... I'm still developing !!)
#include<bits/stdc++.h>

using namespace std;
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb emplace_back
#define endl '\n'
#define VARIABLE_ERROR(x) cout << #x << " = " << x << endl;
#define CONTAINER_ERROR(v) cout << "{";for (auto &x:v) { cout << x << ','; }cout << "}" << endl;
#define PI 3.14159265358979323846
#define M 1000000007
#define INF 1e15
typedef long long ll;

ll sol(ll pos, ll sum, ll flag, string &s, ll n, ll d, vector<vector<vector<ll> > > &dp) {
    if (pos == n) {
        return (sum == 0);
    }
    if (dp[pos][sum][flag] != -1) {
        return dp[pos][sum][flag];
    }
//    sum = (sum * 10) % d;
    ll ans = 0;
    ll limit = flag ? s[pos] - '0' : 9;
    for (ll i = 0; i <= limit; i++) {
        ll nf = 0;
        if(i == limit && flag == 1) {
            nf = 1;
        }
        ans += sol(pos + 1, (sum + i) % d, nf, s, n, d, dp);
        ans = (ans % M);
    }
    return dp[pos][sum][flag] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    ll d;
    cin >> d;
    ll n = s.size();
    vector<vector<vector<ll> > > dp(n + 1, vector<vector<ll> >(d + 1, vector<ll>(2, -1)));
    ll ans = sol(0, 0, 1, s, n, d, dp);
    ans = (ans - 1 + M) % M;
    cout << ans;
//    reverse(s.begin(), s.end());
//    for (ll i = 0; i <= (s[0] - '0'); i++) {
//        dp[0][i % d][0] = (dp[0][i % d][0] + 1) % M;
//    }
//    for (ll i = s[0] - '0' + 1; i <= 9; i++) {
//        dp[0][i % d][1] = (dp[0][i % d][1] + 1) % M;
//    }
//    for (ll rem = 0; rem < d; rem++) {
//        dp[0][rem][1] = (dp[0][rem][1] + dp[0][rem][0]) % M;
//    }
//    for (ll i = 1; i < n; i++) {
//        ll limit = s[i] - '0';
//        for (ll rem = 0; rem < d; rem++) {
//            for (ll val = 0; val < limit; val++) {
//                ll newRem = (rem + pow10[i] * val) % d;
//                dp[i][newRem][0] = (dp[i][newRem][0] + dp[i - 1][rem][1]) % M;
//            }
//            for (ll val = limit; val < 10; val++) {
//                ll newRem = (rem + pow10[i] * val) % d;
//                dp[i][newRem][1] = (dp[i][newRem][1] + dp[i - 1][rem][1]) % M;
//            }
//        }
//    }
//    cout << dp[n - 1][0][0] << endl;
    return 0;
}