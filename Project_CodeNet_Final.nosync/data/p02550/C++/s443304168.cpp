#include<bits/stdc++.h>
//#include<atcoder/all>

using namespace std;
//using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){
  
  ll n,x,m;
  ll X;
  cin >> n >> x >> m;
  X = x;
  vector<vector<pair<int,ll>>> nxt(m,vector<pair<int,ll>>(60,make_pair(-1,-1)));
  while(nxt[x][0].second == -1){
    nxt[x][0] = make_pair(x*x%m,x);
    x = x*x%m;
  }
  for(int j = 1;j < 60;j++){
    rep(i,m){
      if(nxt[i][j-1].second < 0)continue;
      nxt[i][j].second = nxt[i][j-1].second + nxt[nxt[i][j-1].first][j-1].second;
      nxt[i][j].first = nxt[nxt[i][j-1].first][j-1].first;
    }
  }
  ll res = 0;
  rep(i,60){
    if(n >> i & 1){
      res += nxt[X][i].second;
      X = nxt[X][i].first;
    }
  }
  cout << res << "\n";



  return 0;
}