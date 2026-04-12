#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

const ll INF=1000100010001000100;
ll dp[3001][3001][2];
ll a[3001];
int n;
ll dfs(int l,int r){
    int cur=abs(l+n-1-r);
    int b=cur&1;
    if(dp[l][r][b]!=INF) return dp[l][r][b];
    
    ll ret;
    if(cur&1){
        if(l==r) return dp[l][l][b]=-a[l];
        ret=dfs(l+1,r)-a[l];
        ret=min(ret,dfs(l,r-1)-a[r]);
    }
    else{
        if(l==r) return dp[l][l][b]=a[l];
        ret=dfs(l+1,r)+a[l];
        ret=max(ret,dfs(l,r-1)+a[r]);
    }
    return dp[l][r][b]=ret;
}
int main(){
    cin>>n;
    rep(i,n) cin>>a[i];
    rep(i,n)rep(j,n) dp[i][j][0]=INF,dp[i][j][1]=INF;
    cout<<dfs(0,n-1)<<endl;
    return 0;
}
