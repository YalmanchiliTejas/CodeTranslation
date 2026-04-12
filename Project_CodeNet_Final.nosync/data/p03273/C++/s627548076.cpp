#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

#define REP(i,n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> pint;

int main() {
  int H, W; cin>>H>>W;
  vector<bool> row(H, true), col(W, true);
  vector<string> a(H);
  REP(h, H) {
    cin>>a[h];
    REP(w, W) {
      if(a[h][w] == '#') {
	row[h] = false;
	break;
      }
    }
  }
  REP(w, W) {
    REP(h, H) {
      if(a[h][w] == '#') {
        col[w] = false;
	break;
      }
    }
  }
  REP(h, H) {
    if(row[h]) continue;
    REP(w, W) {
      if(col[w]) continue;
      cout << a[h][w];
    }
    cout << endl;
  }

  return 0;
}
