#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
inline long long mod(long long n,long long m){return(n%m+m)%m;}
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

int n;
long long a[3010];
// dp[l][r]:=[l,r]が残っているときのx-y
long long dp[3010][3010];
long long dfs(int l,int r,int who){
    // cout<<l<<" "<<r<<" "<<who<<endl;
    if(dp[l][r]!=LINF) return dp[l][r];
    if(l==r){
        if(who==0) dp[l][r]=a[l];
        else dp[l][r]=-a[l];
        return dp[l][r];
    }
    long long ret;
    if(who==0){
        ret=-LINF;
        ret=max(ret,dfs(l+1,r,(who+1)%2)+a[l]);
        ret=max(ret,dfs(l,r-1,(who+1)%2)+a[r]);
    }else{
        ret=LINF;
        ret=min(ret,dfs(l+1,r,(who+1)%2)-a[l]);
        ret=min(ret,dfs(l,r-1,(who+1)%2)-a[r]);
    }
    dp[l][r]=ret;
    return ret;
}
int main(){
    cin>>n;
    rep(i,n) cin>>a[i];
    rep(i,3010)rep(j,3010) dp[i][j]=LINF;
    cout<<dfs(0,n-1,0)<<endl;
    // rep(i,n) cout<<dp[i][i]<<endl;
    return 0;
}
