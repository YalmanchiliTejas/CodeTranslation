#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define all(x)    (x).begin(),(x).end()
typedef long long ll;
const int MOD = (int)1e9 + 7;

int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<char> > a(h,vector<char>(w));
  rep(i,h) rep(j,w) cin >> a[i][j];
  vector<int> r,c;
  rep(i,h){
    bool flag = true;
    rep(j,w) flag &= a[i][j] == '.';
    if(flag) r.push_back(i);
  }
  rep(j,w){
    bool flag = true;
    rep(i,h) flag &= a[i][j] == '.';
    if(flag) c.push_back(j);
  }
  rep(i,h){
    bool fa = false;
    for(buf:r) if(buf == i) fa = true;
    if(fa) continue;
    rep(j,w){
      bool fb = false;
      for(buf:c) if(buf == j) fb = true;
      if(fb) continue;
      cout << a[i][j];
    }
    cout << endl;
  }
}

