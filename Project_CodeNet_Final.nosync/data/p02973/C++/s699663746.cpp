#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
int n;
int main(void) {
    cin>>n;
    int a[n];
    rep(i,n)cin>>a[i];
    rep(i,n)a[i]*=-1;
    int dp[n+1];
    rep(i,n+1)dp[i]=1<<30;
    rep(i,n){
        auto pt = upper_bound(dp,dp+n,a[i]);
        *pt=a[i];
    }
    int res=0;
    while(dp[res]!=(1<<30))res++;
    cout << res << endl;
    return 0;
}
