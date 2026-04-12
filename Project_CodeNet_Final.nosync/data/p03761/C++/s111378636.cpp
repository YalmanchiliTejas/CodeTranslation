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

int main(){
  int n;
  cin >> n;
  
  vector<string> vec(n);
  rep(i,n) cin >> vec[i];

  int a[26]={};
  rep(i,vec[0].size()){
    a[vec[0][i]-'a']++;
  }
  rep(i,vec.size()-1){
    int b[26]={};
    rep(j,vec[i+1].size()){
      b[vec[i+1][j]-'a']++;
    }
    rep(j,26){
      a[j]=min(a[j],b[j]);
    }
  }
  rep(i,26){
    if(a[i]){
      rep(j,a[i]) cout<<char('a'+i);
    }
  }
  
  cout<<endl;
  
  
}
    
