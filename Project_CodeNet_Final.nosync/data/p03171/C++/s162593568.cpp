#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())
#define fi first
#define se second

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<'\n';
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;
const ll inf=1e15;

int n;
vector<ll> a(3010);
vector<vector<ll>> dp(3010,vector<ll>(3010,-1));

ll dfs(ll l,ll r){
  if(dp[l][r]!=-1) return dp[l][r];
  if((l+r)%2!=n%2){
    if(r-l==1) return dp[l][r]=-a[l];
    return dp[l][r]=min(dfs(l+1,r)-a[l],dfs(l,r-1)-a[r-1]);
  }else{
    if(r-l==1) return dp[l][r]=a[l];
    return dp[l][r]=max(dfs(l+1,r)+a[l],dfs(l,r-1)+a[r-1]);
  }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,n) cin>>a[i];
    cout<<dfs(0,n)<<endl;
}