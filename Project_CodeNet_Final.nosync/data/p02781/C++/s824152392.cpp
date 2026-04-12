#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define repr(i, n) REPR(i, n, 0)
#define REPR(i, s, e) for(int i=(int)(s-1); i>=(int)(e); i--)
#define pb push_back
#define all(r) r.begin(),r.end()
#define rall(r) r.rbegin(),r.rend()
#define fi first
#define se second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const double EPS = 1e-8;

template<typename T> T chmax(T& a, const T& b){return a = (a > b ? a : b);}
template<typename T> T chmin(T& a, const T& b){return a = (a < b ? a : b);}

ll dp[110][10][5][2];

ll calc(ll n, ll k) {
    if(n < k) return 0;
    ll ret = 1LL;
    for(ll i = n; i > n - k; --i) ret *= i;
    REP(i, 1, k+1) ret /= i;
    return ret;
}

int main(){
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    ll ans = calc(n-1, k)*pow(9, k);
    // cout << ans << endl;
    {
        int d = s[0]-'0';
        REP(num, 1, d+1) {
            dp[0][num][1][(num==d?1:0)] = 1;
        }
    }
    REP(i, 1, n) {
        int d = s[i] - '0';
        rep(num, 10) rep(pre, 10) {
            rep(j, k+1) {
                dp[i][num][j+(num != 0 ? 1 : 0)][0] += dp[i-1][pre][j][0];
                if(d == num) dp[i][num][j+(num != 0 ? 1 : 0)][1] += dp[i-1][pre][j][1];
                if(num < d) dp[i][num][j+(num != 0 ? 1 : 0)][0] += dp[i-1][pre][j][1];
            }
        }
    }
    rep(num, 10) {
        ans += dp[n-1][num][k][0] + dp[n-1][num][k][1];
        // cout << num << " " << dp[n-1][num][k][0] << " " << dp[n-1][num][k][1] << endl;
    }
    cout << ans << endl;
    return 0;
}