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


signed main(){
    int n; cin >> n;
    ll a[n];
    rep(i,n) cin >> a[i];
    if(n%2==0){
        ll l[n/2+1],r[n/2+1];
        l[0]=r[0]=0;
        for(int i=0;2*i<n;i++){
            l[i+1]=l[i]+a[2*i];
            r[i+1]=r[i]+a[n-1-(2*i)];
        }
        ll ans=l[n/2];
        rep(i,n/2+1){
            chmax(ans,l[i]+r[n/2-i]);
        }
        cout << ans << endl;
    }else{
        ll dp[n][3];
        dp[0][0]=0; dp[0][1]=a[0];
        rep(i,n-1){
            if(i==0){
                dp[1][0]=dp[0][0];
                dp[1][1]=dp[0][0]+a[1];
                dp[1][2]=dp[0][1];
            }
            else if(i%2==0){
                dp[i+1][0]=max(dp[i][0],dp[i][1]);
                dp[i+1][1]=dp[i][1]+a[i+1];
                dp[i+1][2]=dp[i][2];
            }else{
                dp[i+1][0]=dp[i][0]+a[i+1];
                dp[i+1][1]=max(dp[i][1],dp[i][2]);
                dp[i+1][2]=dp[i][2]+a[i+1];
            }
        }
        cout << max(dp[n-1][0],dp[n-1][1]) << endl;
    }
}
