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
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();

    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(5, vector<ll>(2, 0)));
    dp[0][0][0] = 1;

    REP(i, n){
        int d = s[i] - '0';
        REP(j, 4){
            REP(c, 10){
                if(c <= d){
                    dp[i+1][j + (c > 0)][(c < d)] += dp[i][j][0];
                }
                dp[i+1][j + (c > 0)][1] += dp[i][j][1];
            }
        }
    }

    cout << dp[n][k][0] + dp[n][k][1] << endl;
    return 0;
}
