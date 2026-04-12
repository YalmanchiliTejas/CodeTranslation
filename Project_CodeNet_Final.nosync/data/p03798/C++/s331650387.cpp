#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n;
  string s;
  cin >> n >> s;
  s = s[n-1]+s+s[0];
  vector<bool>ss(n+2),sw(n+2),ws(n+2),ww(n+2);
  ss[0] = 1;ss[1] = 1;
  sw[0] = 1;sw[1] = 0;
  ws[0] = 0;ws[1] = 1;
  ww[0] = 0;ww[1] = 0;
  vector<bool>v(n+2);
  rep(i,0,4){
    if(i == 0) v = ss;
    if(i == 1) v = sw;
    if(i == 2) v = ws;
    if(i == 3) v = ww;
    rep(j,1,n+1){
      if(s[j] == 'o'){
        if(v[j]) v[j+1] = v[j-1];
        else v[j+1] = !v[j-1];
      }
      else{
        if(v[j]) v[j+1] = !v[j-1];
        else v[j+1] = v[j-1];
      }
    }
    if(v[0] == v[n] && v[1] == v[n+1]){
      rep(j,1,n+1){
        if(!v[j]) cout << 'W';
        else cout << 'S';
      }
      cout << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}