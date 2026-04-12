#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll H,W;
  cin >> H >> W;
  char c[10][10];
  rep(i,0,H){
    rep(j,0,W){
      cin >> c[i][j];
    }
  }
  ll cnt = 0;
  rep(i,0,H){
    rep(j,0,W){
      if(c[i][j] == '#') cnt++;
    }
  }
  if(cnt != H+W-1){
    print("Impossible");
    return 0;
  }
  queue<lpair> lp;
  lp.push(make_pair(0,0));
  ll dx[2] = {0,1};
  ll dy[2] = {1,0};
  while(!lp.empty()){
    lpair l1 = lp.front();
    if(l1.first == H-1 && l1.second == W-1){
      print("Possible");
      return 0;
    }
    lp.pop();
    rep(i,0,2){
      ll hh = l1.first + dx[i];
      ll ww = l1.second + dy[i];
      if(hh >= 0 && hh < H && ww >= 0 && ww < W){
        if(c[hh][ww] == '#') lp.push(make_pair(hh,ww));
      } 
    }
  }
  print("Impossible");
}