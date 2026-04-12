#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for( ll i = 0;i < (ll)n;++i)
vector<ll> dx = {1,0};
vector<ll> dy = {0,1};

ll h,w;
vector<string> a;
vector<vector<ll>> m;

void dfs( ll y, ll x ){
  m.at(y).at(x) = 2;
  if( y+1 <= h-1 && x+1 <= w-1 ){
    if( a.at(y+1).at(x) == '#' && a.at(y).at(x+1) == '#' ){
      return;
    }
  }
  rep(i,2){
    ll ny = y + dy.at(i);
    ll nx = x + dx.at(i);
    if( ny >= 0 && ny <= h-1  && nx >= 0 && nx <= w-1 &&
        a.at(ny).at(nx) == '#' && m.at(ny).at(nx) != 2 ){
      //cout << ny << " " << nx << endl;
      dfs(ny,nx);
    }
  }
}

int main(){
  
  cin >> h >> w;
  a.resize(h);
  rep(i,h) cin >> a.at(i);
  m.resize(h);
  rep(i,h) m.at(i).resize(w);

  rep(i,h){
    rep(j,w){
      if( a.at(i).at(j) == '#' ) m.at(i).at(j) = 1;
    }
  }
  dfs(0,0);
  rep(i,h){
    rep(j,w){
      if( m.at(i).at(j) == 1  ){
       // cout << i << " " << j << endl;
        cout << "Impossible" << endl;
        return 0;
      }
    }
  }
  cout << "Possible" << endl;
  return 0;
}