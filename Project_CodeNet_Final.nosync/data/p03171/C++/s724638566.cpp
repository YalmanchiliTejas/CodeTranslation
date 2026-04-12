#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using stkll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << ": " << x << endl;
#else
    #define debug(x)
#endif


ll dp[3100][3100];

int main() {
    cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(20);

    ll N; cin >> N;
    vll a(N);
    rep(i,N) cin >> a[i];

    for(ll w = 1; w <= N; w++) {
        rep(l, N) {
            ll r = l + w;
            if(w % 2 == N % 2) {
                dp[l][r] = max(dp[l+1][r] + a[l], dp[l][r-1] + a[r-1]);
            }
            else {
                dp[l][r] = min(dp[l+1][r] - a[l], dp[l][r-1] - a[r-1]);
            }
        }
    }
    cout << dp[0][N] << endl;
}
