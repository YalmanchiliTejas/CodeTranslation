#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
#define fo(i,s,e) for( i=s;i<e;i++)
#define rfo(i,s,e) for(i=s;i>e;i--)
#define LLI long long int
#define LI long int 
#define pb push_back
#define pob pop_back()
#define sp " "
#define ff first
#define ss second
//               When something is important enough, you do it even if the odds are not in your favor.
LLI dp[3004][3004];
LI a[3004];
void solve(LI l,LI r,bool f){
  if(l==r) {
    if(f) dp[l][r]=a[l];
    else dp[l][r]=0;
    return;
  }
  if(dp[l][r]==-1){
    if(dp[l][r-1]==-1) solve(l,r-1,f);
    if(dp[l+1][r]==-1) solve(l+1,r,f);
    if(f==(r-l+1)%2) dp[l][r]=max(a[r]+dp[l][r-1],a[l]+dp[l+1][r]);
    else dp[l][r]=min(dp[l][r-1],dp[l+1][r]);
  }
}
int main(){   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif*/
    // code goes here
    int t=1;//cin>>t;
    while(t--){
      LI n,i;cin>>n;
      LLI sum=0;
      memset(dp,-1,sizeof(dp));
      fo(i,0,n){ cin>>a[i];sum+=a[i];}
      bool f;
      if(n%2) f=1;
      else f=0; 
      solve(0,n-1,f);//cout<<dp[0][n-1];
      cout<<2*dp[0][n-1]-sum;
    }
    return 0;
}