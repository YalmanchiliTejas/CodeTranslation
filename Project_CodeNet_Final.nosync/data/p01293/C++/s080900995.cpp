#include<iostream>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

int p[300];

int main() {
  rep (i, 10) p['0' + i] = i;
  p['T'] = 10;
  p['J'] = 11;
  p['Q'] = 12;
  p['K'] = 13;
  p['A'] = 14;
  while (true) {
    string trump;
    cin >> trump;
    if (trump == "#") break;
    string cards[4][13];
    rep (i, 4) rep (j, 13) cin >> cards[i][j];
    int ew = 0, ns = 0, now = 0;
    rep (j, 13) {
      int ii = 0, r = 0;
      rep (i, 4) {
	int rr = 0;
	if (cards[i][j][1] == trump[0]) {
	  rr = 20 + p[(int)cards[i][j][0]];
	} else if (cards[i][j][1] == cards[now][j][1]) {
	  rr = p[(int)cards[i][j][0]];
	} else {
	  rr = 0;
	}
	if (rr > r) {
	  r = rr;
	  ii = i;
	}
      }
      if (ii % 2 == 0) ++ns;
      else ++ew;
      now = ii;
    }
    if (ns > ew) cout << "NS " << ns - 6 << endl;
    else cout << "EW " << ew - 6 << endl;
  }
  return 0;
}