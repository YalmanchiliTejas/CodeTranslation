#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
 
const int MOD=1000000007;
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;
ll gcd(ll x, ll y){
  if(y==0) return x;
  else return gcd(y, x%y);
}
ll lcm(ll x,ll y){
  ll g=gcd(x,y);
  return x/g*y;
}

using Graph=vector<vector<int>>;
Graph G;

void dfs(int v,vector<bool> &seen,int &sum){
  bool end=true;
  rep(i,seen.size()){
    if(!seen[i] && i!=v){
      end=false;
    }
  }
  if(end){
      sum++;
      return ;
  }
  seen[v]=true;
  for(auto nv :G[v]){
    if(seen[nv])continue;
    dfs(nv,seen,sum);
  }
  seen[v]=false;
}

int main(){
  int n,m;
  cin >> n >> m;  
  
  G.assign(n,vector<int>());
  rep(i,m){
    int a,b;
    cin >> a>> b;
    a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<bool>seen(n,false);
  int sum=0;
  dfs(0,seen,sum);
  cout<<sum<<endl;
}
