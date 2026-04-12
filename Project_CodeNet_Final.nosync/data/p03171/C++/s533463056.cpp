#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define all(a) a.begin(),a.end()
#define P pair<int,int>
#define F first
#define S second
#define mod 1000000007
#define INF 9000000000000000000
int dp[3010][3010];
int V[3010];
int solve(int r,int l,bool wh){
    if(dp[r][l]!=INF)return dp[r][l];
    int res;
    if(r==l){
        if(wh)res=V[r];
        else res=-V[r];
    }
    else{
        if(wh)
            res=max(solve(r+1,l,!wh)+V[r],solve(r,l-1,!wh)+V[l]);
        else
            res=min(solve(r+1,l,!wh)-V[r],solve(r,l-1,!wh)-V[l]);
    }
    return dp[r][l]=res;
}
signed main(void){
    int n;cin>>n;
    rep(i,3010)rep(j,3010)dp[i][j]=INF;
    rep(i,n)cin>>V[i];
    cout<<solve(0,n-1,true)<<endl;
}