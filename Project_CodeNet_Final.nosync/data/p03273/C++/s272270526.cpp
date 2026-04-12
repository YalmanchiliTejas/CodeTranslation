#include<bits/stdc++.h>
#define rep(i, n) for(int (i)=0 ;i <(n); ++(i))
#define REP(i,m,n) for(int (i) = (m); (i) <= (n); ++(i))
#define yorn(f) puts((f)?"Yes":"No")
#define YORN(f) puts((f)? "YES":"NO")
typedef long long ll;
using namespace std;

void pri(vector<string> a) {
  rep(i, a.size()) {
    cout << a[i] << endl;
  }
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> b(h);
  rep(i, h) cin >> b[i];

  bitset<110> okx;
  bitset<110> oky;

  rep(i, h) {
    rep(j, w) {
      if(b[i][j] == '#') {
        okx.set(i, true);
        oky.set(j, true);
      }
    }
  }

  rep(i, h) {
    if(okx.test(i)) {
      rep(j, w) {
        if(oky.test(j)) {
          cout << b[i][j] << flush;
        }
      }
      cout << endl;
    }
  } 
  return 0;
}