#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
const ll n_max=3000;
ll a[n_max];
ll dp[n_max][n_max];


ll dfs(ll l, ll r){
  if(r==l){
    dp[r][r]=a[r];
    return a[r]; 
  }
  else{
    ll tl,tr;
    if(dp[l+1][r]==-1){
      tl=dfs(l+1,r);
    }
    else tl=dp[l+1][r];
    if(dp[l][r-1]==-1){
      tr=dfs(l,r-1);
    }
    else tr=dp[l][r-1];
    dp[l][r]= max(a[l]-tl,a[r]-tr);
    return max(a[l]-tl,a[r]-tr);
  }
}

int main(){
  rep(i,n_max) rep(j,n_max) dp[i][j]=-1;
  
  ll n;
  cin >> n;
  rep(i,n) cin >> a[i];
  cout << dfs(0,n-1) << endl;
  
  
  return 0;

}
