#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll N;
    cin >> N;
    vll a(N);
    rep(i, N) cin >> a[i];
    reverse(a.begin(), a.end());
    vll dp(N+1);
    rep(i, N+1) dp[i] = INF;

    rep(i, N) *upper_bound(dp.begin(), dp.end(), a[i]) = a[i];

    rep(i, N+1) debug(dp[i]);

    ll ans = lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
    cout << ans << endl;
}
