#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <queue>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
const int INF = 1<<29;

int main() {
  string left = "qwertasdfgzxcvb";
  string s;
  while(cin >> s, s!="#") {
    int res = 0;
    int l = -1;
    REP(i,s.size()) {
      if (find(ALL(left), s[i])!=left.end()) {
        if (l!=1) {
          res++;
          l = 1;
        }
      } else {
        if (l!=0) {
          res++;
          l = 0;
        }
      }
    }
    cout << res-1 << endl;
  }
}