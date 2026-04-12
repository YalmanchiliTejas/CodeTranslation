#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

const ll N=3010;
vec a(N);
mat dp(N,vec(N,inf));
ll n;

ll dfs(ll l,ll r) {
  ll use=n-(r-l+1);
  if(l==r) {
    if(use%2) return -a[l];
    else return a[l];
  }
  if(dp[l][r]!=inf) return dp[l][r];
  ll res;
  if(use%2) {
    res=min(dfs(l+1,r)-a[l],dfs(l,r-1)-a[r]);
  }
  else {
    res=max(dfs(l+1,r)+a[l],dfs(l,r-1)+a[r]);
  }
  return dp[l][r]=res;
}

int main() {
  cin >> n;
  for(ll i=0;i<n;i++) cin >> a[i];
  cout << dfs(0,n-1) << endl;
}