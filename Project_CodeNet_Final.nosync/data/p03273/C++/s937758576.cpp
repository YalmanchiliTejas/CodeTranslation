#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repr(i, n) for(int i = (int)(n); i >= 0; i--)
#define repm(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define repmr(i, m, n) for(int i = (int)(n); i >= (int)(m); i--)
#define all(x) (x).begin(),(x).end()
#define inf 2e9
#define MOD 1000000007

using namespace std;
typedef long long int lli;
typedef long long ll;

int main(){
  int h,w; cin >> h >> w;
  vector<vector<char>> a(h, vector<char>(w));
  rep(i,h) rep(j,w){
    cin >> a[i][j];
  }

  vector<bool> white_h(h,false), white_w(w,false);
  rep(i,h){
    bool isWhite = true;
    rep(j,w){
      if(a[i][j] == '#'){
        isWhite = false;
        break;
      }
    }
    if(isWhite) white_h[i] = true;
  }

  rep(i,w){
    bool isWhite = true;
    rep(j,h){
      if(a[j][i] == '#'){
        isWhite = false;
        break;
      }
    }
    if(isWhite) white_w[i] = true;
  }

  rep(i,h){
    if(white_h[i]) continue;
    rep(j,w){
      if(white_w[j]) continue;
      cout << a[i][j];
    }
    cout << endl;
  }
}
