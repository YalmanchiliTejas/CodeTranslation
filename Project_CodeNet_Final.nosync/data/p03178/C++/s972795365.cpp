#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, a, n) for (ll i = (a); i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    string k;
    ll D;
    cin >> k >> D;
    ll n = k.length();

    ll dp[10100][110][2];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    rep(dgt, 0, n) rep(d, 0, D) rep(flg, 0, 2) {
        ll c = k[dgt] - '0';
        rep(nxt, 0, 10) {
            if (nxt < c) (dp[dgt+1][(d+nxt)%D][1] += dp[dgt][d][flg]) %= MOD;
            else if (nxt == c) (dp[dgt+1][(d+nxt)%D][flg] += dp[dgt][d][flg]) %= MOD;
            else {
                if (flg) (dp[dgt+1][(d+nxt)%D][flg] += dp[dgt][d][flg]) %= MOD;
            }
        }
    }
    ll ans = (dp[n][0][0] + dp[n][0][1]) % MOD;
    ans = (ans + MOD - 1) % MOD;
    cout << ans << endl;
}