#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MIN(a) *min_element(all(a))
#define MAX(a) *max_element(all(a))
#define SUM(a) accumulate(all(a), 0LL)
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define RREP(i, n) for(int (i)=(n)-1; (i)>=0; (i)--)
#define FOR(i, m, n) for(int (i)=(m); (i)<(n); i++)
#define FORR(i, m, n) for(int (i)=(n)-1; (i)>=(m); i--)
#define debug(x) cerr << #x << " = " << x << endl
//#define int long long

typedef long long ll;
//ll const MOD = 998244353;
ll const MOD = 1e9+7;
int const inf = 1e9;
ll const INF = 1e18;

inline void ios_(){cin.tie(0); ios::sync_with_stdio(false);}
template<typename T> int size(const T& a){return (int)a.size();}
template<typename T> T Div(T a, T b){return (a + b - 1) / b;}
template<typename T> bool chmin(T& a, const T& b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, const T& b){if(a < b){a = b; return true;} return false;}



signed main(){
    int n;
    cin >> n;
    vector<ll> v(n);
    for(auto& i : v) cin >> i;

    v.push_back(-1e13);
    if(n%2 == 0) v.push_back(-1e13);
    int m = v.size();
    vector<vector<vector<ll>>> dp(m, vector<vector<ll>>(2, vector<ll>(3, -1e13)));

    REP(i, m){
        if(i == 0){
            dp[0][0][0] = 0;
            dp[0][1][0] = v[0];
            continue;
        }

        dp[i][0][0] = dp[i-1][1][0];
        dp[i][1][0] = dp[i-1][0][0] + v[i];

        dp[i][0][1] = max(dp[i-1][0][0], dp[i-1][1][1]);
        dp[i][1][1] = dp[i-1][0][1] + v[i];

        dp[i][0][2] = max(dp[i-1][0][1], dp[i-1][1][2]);
        dp[i][1][2] = dp[i-1][0][2] + v[i];
    }

    ll ans = -INF;
    chmax(ans, dp[m-1][0][1]);
    chmax(ans, dp[m-1][1][1]);
    chmax(ans, dp[m-1][0][2]);
    chmax(ans, dp[m-1][1][2]);
    cout << ans << endl;

    return 0;
}
