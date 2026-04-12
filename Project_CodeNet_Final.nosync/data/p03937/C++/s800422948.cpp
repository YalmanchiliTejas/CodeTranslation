#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int H, W;
  cin >> H >> W;
  int cnt = 0;
  rep(i,H) {
    rep(j,W) {
      char x;
      cin >> x;
      if(x=='#') cnt++;
    }
  }
  cout << (cnt==H+W-1? "Possible" : "Impossible") << endl;
}
