#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define REP1(i,n) for(int i=1; i<=(int)(n); i++)
#define SORT(v) sort(v.begin(), v.end())
#define REVERSE(v)  reverse(v.begin(), v.end())
using namespace std;

int main() {
  int H,W; cin>>H>>W;
  bool black = false;
  vector<bool> blackH(H);
  vector<bool> blackW(W);
  char a[H][W];
  REP(i,H) {
    REP(j,W) {
      cin>>a[i][j];
      if(a[i][j] == '#') black = true;
    }
    if(black) blackH[i] = true;
    else blackH[i] = false;
    black = false;
  }

  REP(i,W) {
    REP(j,H) {
      if(a[j][i] == '#') black = true;
    }
    if(black) blackW[i] = true;
    else blackW[i] = false;
    black = false;
  }

  REP(i,H) {
    if(blackH[i]) {
      REP(j,W) {
        if(blackW[j])
          cout<<a[i][j];
        }
      cout<<endl;
    }
  }
  return 0;
}