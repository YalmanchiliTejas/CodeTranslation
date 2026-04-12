#include <bits/stdc++.h> 
using namespace std;
using ll=long long;
const int N=3005;
int a[N];
ll memo[N][N][3];
bool vis[N][N][3];
ll dp(int l,int r,int t){
    if(vis[l][r][t]) return memo[l][r][t];
    if(l>r) return 0LL;
    ll ans;
    if(t==0){
        ans=max(a[l]+dp(l+1,r,1),a[r]+dp(l,r-1,1));
    }else{
        ans=min(-a[l]+dp(l+1,r,0),-a[r]+dp(l,r-1,0));
    }
    vis[l][r][t]=true;
    return memo[l][r][t]=ans;
    
}
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<dp(0,n-1,0)<<"\n";
  
    return 0;
}
