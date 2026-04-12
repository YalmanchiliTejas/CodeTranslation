#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007

vector<ll> len(60,1),p(60,1);

ll dfs(ll n,ll x){
  if(n == 0)return x ? 1 : 0;
  if(x == 1)return 0;
  else if(x <= len[n-1]+1)return dfs(n-1,x-1);
  else if(x == len[n-1]+2)return p[n-1]+1;
  else if(x <= 2*len[n-1]+2)return p[n-1]+1+dfs(n-1,x-len[n-1]-2);
  else return p[n-1]*2+1;
}

int main(){
  
  rep(i,55)len[i+1] = 2*len[i]+3;
  rep(i,55)p[i+1] = 2*p[i]+1;
  ll n,x;
  cin >> n >> x;
  cout << dfs(n,x) << "\n";
  





  return 0;
}