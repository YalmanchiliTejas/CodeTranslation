#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

ll memo[55];
ll sum[55];

ll f(ll n){
  if(n==0) return sum[0]=1;
  if(sum[n]) return sum[n];
  return sum[n]=2*f(n-1)+3;
}

ll dfs(ll n, ll x){
  if(x<=0) return 0;
  if(n==0) return 1;
  if(memo[n]&&sum[n]==x) return memo[n];
  ll ret=dfs(n-1,min(sum[n-1],x-sum[n-1]-2))+(sum[n]/2<x? 1:0)+dfs(n-1,min(sum[n-1],x-1));
  if(sum[n]==x) memo[n]=ret;
  return ret;
}

int main() {
  ll n,x;
  cin>>n>>x;
  f(n);
  cout<<dfs(n,x)<<endl;
  return 0;
}

