#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i >= 0; i--)
#define REP(i, m, n) for (int i = (int)(m); i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;

int main(){
  int H, W; cin >> H >> W;
  vector<string> field(H);
  rep(i, H) cin >> field[i];

  vector<bool> h_ok(H, false);
  vector<bool> w_ok(W, false);

  rep(i, H){
    rep(j, W){
      if(field[i][j] == '#'){
        h_ok[i] = true;
        break;
      }
    }
  }

  rep(j, W){
    rep(i, H){
      if(field[i][j] == '#'){
        w_ok[j] = true;
        break;
      }
    }
  }

  rep(i, H) if(h_ok[i]){
    rep(j, W) if(w_ok[j]){
      cout << field[i][j];
    }
    cout << endl;
  }

  return 0;
}
