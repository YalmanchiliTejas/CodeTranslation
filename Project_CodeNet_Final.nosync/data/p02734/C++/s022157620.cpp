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
    ll dp[n+1][3030];
    memset(dp,0,sizeof(dp));
    rep(i,n+1) dp[i][0]=i+1;
    rep(i,n){
        int a; cin >> a;
        for(int j=0;j<3030;j++){
            if(j!=0){
                dp[i+1][j]+=dp[i][j];
                dp[i+1][j]%=MOD;
            }
            if(j+a<3030){
                dp[i+1][j+a]+=dp[i][j];
                dp[i+1][j+a]%=MOD;
            }
        }
    }
    ll ans=0;
    rep(i,n){
        ans+=((dp[i+1][s]-dp[i][s]+MOD)%MOD)*(n-i);
        ans%=MOD;
    }
    cout << ans << endl;
}
