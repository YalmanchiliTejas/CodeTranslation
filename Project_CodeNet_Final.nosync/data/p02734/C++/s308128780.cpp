#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define repp(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ppb pop_back()
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;

const ll MOD = 998244353;

signed main(){
    int n,s; cin >> n >> s;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    ll dp[n+1][s+1][3];
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    rep(i,n){
        rep(j,s+1){
            dp[i+1][j][0]=dp[i][j][0];
            dp[i+1][j][1]=dp[i][j][0]+dp[i][j][1];
            dp[i+1][j][2]=dp[i][j][0]+dp[i][j][1]+dp[i][j][2];
            rep(k,3)dp[i+1][j][k]%=MOD;
            if(j-a[i]>=0){
                dp[i+1][j][1]+=dp[i][j-a[i]][0]+dp[i][j-a[i]][1];
                dp[i+1][j][2]+=dp[i][j-a[i]][0]+dp[i][j-a[i]][1];
                rep(k,3)dp[i+1][j][k]%=MOD;
            }
        }
    }
    cout << dp[n][s][2] << endl;
}
