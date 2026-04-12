#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int main(){
  ll H, W;
  cin >> H >> W;
  vvc a(H, vc(W));
  rep(i, H){
    rep(j, W) cin >> a[i][j];
  }

  vvl b(H, vl(W, 1));
  rep(i, H){
    bool found = false;
    rep(j, W) found = found || (a[i][j] == '#');
    if(!found){
      rep(j, W) b[i][j] = 0;
    }
  }

  rep(j, W){
    bool found = false;
    rep(i, H) found = found || (a[i][j] == '#');
    if(!found){
      rep(i, H) b[i][j] = 0;
    }
  }

  ll plot;
  rep(i, H){
    plot = 0;

    rep(j, W){
      if(b[i][j] == 1){
        cout << a[i][j];
        plot++;
      }
    }

    if(plot > 0) cout << "\n";
  }
  
  return 0;
}
