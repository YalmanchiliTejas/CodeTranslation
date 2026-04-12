#include <bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
#define mp make_pair
using namespace std;
using ll=long long;
using P=pair<int,int>;
const ll INF=1LL<<30;
const ll LINF=1LL<<61;
const double eps=1e-5;
const ll MOD=1e9+7;
vector<ll> a;
ll dp[3010][3010][2];
ll dfs(int l,int r,int t){
    if(dp[l][r][t]!=-1)return dp[l][r][t];
    if(l==r){
        if(t==0){
            return a[l];
        }else{
            return -a[l];
        }
    }
    ll res;
    if(t==0){
        res=max(dfs(l+1,r,t^1)+a[l],dfs(l,r-1,t^1)+a[r]);
    }else{
        res=min(dfs(l+1,r,t^1)-a[l],dfs(l,r-1,t^1)-a[r]);
    }
    return dp[l][r][t]=res;
}
int main(){
    int n;cin>>n;
    memset(dp,-1,sizeof(dp));
    a.resize(n+10);
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<dfs(0,n-1,0)<<endl;
}   
