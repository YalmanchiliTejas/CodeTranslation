#include <iostream>
#define REP(i, a, n) for(int i = (a); i < (n); i++)
using namespace std;


int main(void) {
  string S;
  while(cin >> S, S != "#") {
    int H = 0, W = 0, m[10][10];
    REP(i, 0, S.length()) {
      char c = S[i];
      if(c == '/') {
        H++;
        W = 0;
      } else if('0' <= c && c <= '9') {
        REP(j, 0, c - '0') {
          m[H][W++] = 0;
        }
      } else if(c == 'b') {
        m[H][W++] = 1;
      }
    }
    H++;

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    m[a - 1][b - 1] = 0;
    m[c - 1][d - 1] = 1;

    string ans = "";
    REP(i, 0, H) {
      REP(j, 0, W) {
        if(m[i][j] == 0) {
          int cnt = 1;
          while(j + 1 < W && m[i][j + 1] == 0) {
            cnt++;
            j++;
          }
          ans += ('0' + cnt);
        } else {
          ans += 'b';
        }
      }
      if(i + 1 != H) {
        ans += '/';
      }
    }

    cout << ans << endl;
  }
}