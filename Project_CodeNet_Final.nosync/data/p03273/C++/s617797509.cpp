#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep2(i, a, n) for(ll i = a; i < (ll)(n); i++)
#define memi cout << endl
#define kono(n) cout << fixed << setprecision(n)
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define hina cout << ' '
#define in(n) cin >> n
#define in2(n, m) cin >> n >> m
#define in3(n, m, l) cin >> n >> m >> l
#define out(n) cout << n
const ll mei = (ll)1e9 + 7;

int main(){
  ll h, w;
  in2(h, w);
  bool k;
  vector<vector<char>> c(h, vector<char> (w));
  vector<bool> d(h, true), e(w, true);
  rep(i, h){
    rep(j, w)
      in(c[i][j]);
  }
  rep(i, h){
    k = true;
    rep(j, w){
      if(c[i][j] != '.')
        k = false;
    }
    if(k)
      d[i] = false;
  }
  rep(i, w){
    k = true;
    rep(j, h){
      if(c[j][i] != '.')
        k = false;
    }
    if(k)
      e[i] = false;
  }
  rep(i, h){
    rep(j, w){
      if(d[i]){
        if(e[j]){
          out(c[i][j]);
        }
      }
    }
    memi;
  }
}