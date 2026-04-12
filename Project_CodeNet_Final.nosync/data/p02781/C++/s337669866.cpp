#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const double PI = 3.1415926535;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;


int main(){
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    vector<vector<vector<ll>>>dp(10010,vector<vector<ll>>(2, vector<ll>(5)));
    dp[0][0][0] = 1;
    rep(i, 0, n){
        rep(j, 0, k+1){
            dp[i+1][1][j+1] += dp[i][1][j]*9;
            dp[i+1][1][j] += dp[i][1][j];
            int p = s[i]-'0';
            if(p>0){
                dp[i+1][1][j+1] += dp[i][0][j]*(p-1);
                dp[i+1][1][j] += dp[i][0][j];
                dp[i+1][0][j+1] = dp[i][0][j];
            }else{
                dp[i+1][0][j] = dp[i][0][j];
            }
        }
    }
    cout << dp[n][1][k]+dp[n][0][k] << endl;
}