#include <bits/stdc++.h>
#define FOR(i,k,n) for(int i=(k);i<(int)(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;

int main() {
  int n;
  cin>>n;
  int mx = 0;
  int cnt = 0;
  REP(i,n) {
    int h;
    cin>>h;
    if (h >= mx) {
      ++cnt;
      mx = h;
    }
  }
  cout << cnt << endl;
  return 0;
}
