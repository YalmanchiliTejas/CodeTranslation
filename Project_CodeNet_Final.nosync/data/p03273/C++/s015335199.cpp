#include <bits/stdc++.h>
using namespace std;
#define long long long
#define read cin >>
#define echo cout <<
#define fin << '\n'
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

int main() {
  int N, M;
  string s;
  read N >> M;
  vector<string> data(N);

  REP(i, N) {
    read s;
    data[i] = s;
  }
  // 横チェック
  REP(i, N) {
    bool erace_flag = true;
    REP(j, M) {
      if (data[i][j] == '#') {
        erace_flag = false;
      }
    }
    if (erace_flag) {
      REP(j, M) { data[i][j] = '-'; }
    }
  }

  // 縦チェック
  REP(j, M) {
    bool erace_flag = true;
    REP(i, N) {
      if (data[i][j] == '#') {
        erace_flag = false;
      }
    }
    if (erace_flag) {
      REP(i, N) { data[i][j] = '-'; }
    }
  }
  REP(i, N) {
    bool endl_flag = false;
    REP(j, M) {
      if (data[i][j] != '-') {
        endl_flag = true;
        if (j == M - 1) {
          cout << data[i][j] << endl;
        } else {
          cout << data[i][j];
        }
      } else if (j == M - 1 && endl_flag) {
        cout << endl;
      }
    }
  }
}