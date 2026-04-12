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
#include <stdio.h>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional> //operator[]
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;

const ll MOD = 998244353;

signed main(){
    int n,s; cin >> n >> s;
    ll dp[n+1][3030][3];
    //dp[i][j][k]:=i番目sum=j k=0,1,2でo,l,lr;
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    rep(i,n){
        int a; cin >> a;
        rep(j,3030){
            
            dp[i+1][j][0]+=dp[i][j][0];
            dp[i+1][j][1]+=dp[i][j][0]+dp[i][j][1];
            dp[i+1][j][2]+=dp[i][j][0]+dp[i][j][1]+dp[i][j][2];
            
            rep(k,3)dp[i+1][j][k]%=MOD;
            
            if(j+a<3030){
                dp[i+1][j+a][1]+=dp[i][j][0]+dp[i][j][1];
                dp[i+1][j+a][2]+=dp[i][j][0]+dp[i][j][1];
                rep(k,3){
                    dp[i+1][j+a][k]%=MOD;
                }
            }
            
        }
    }
    cout << dp[n][s][2] << endl;
}
