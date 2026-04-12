#include <bits/stdc++.h>
using namespace std;

int toInt(char c) {
  if(c == 'T') return 10;
  if(c == 'J') return 11;
  if(c == 'Q') return 12;
  if(c == 'K') return 13;
  if(c == 'A') return 14;
  return c - '0';
}

int getValue(string C, char T, char S) {
  int res = toInt(C[0]);
  if(C[1] == T) res += 200;
  else if(C[1] == S) res += 100;
  return res;
}

int main() {
  for(char T; cin >> T && T != '#'; ) {
    string H[4][13];
    for(int i = 0; i < 4; ++i) {
      for(int j = 0; j < 13; ++j) {
        cin >> H[i][j];
      }
    }
    int res[2] = {};
    int p = 0;
    for(int j = 0; j < 13; ++j) {
      char S = H[p][j][1];
      int maxi = getValue(H[0][j], T, S);
      int winner = 0;
      for(int i = 1; i < 4; ++i) {
        int tmp = getValue(H[i][j], T, S);
        if(maxi < tmp) {
          maxi = tmp;
          winner = i;
        }
      }
      res[winner&1] += 1;
      p = winner;
    }
    if(res[0] > res[1])
      cout << "NS " << res[0] - 6 << endl;
    else
      cout << "EW " << res[1] - 6 << endl;
  }
  return 0;
}