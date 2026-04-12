#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

#define ll long long
#define INF (1 << 30)
#define INFLL (1LL << 60)

#define FOR(i,a,b) for(ll i = (a);i<(b);i++)
#define REP(i,a) FOR(i,0,(a))
#define MP make_pair

int c[30][50];

int main() {
  int n;
  cin >> n;
  string s;

  REP (i, n) {
    cin >> s;
    int len = s.length();
    REP (j, len) {
      //cout << s[j] << endl;
      //cout << s[j] - 'a' << endl;         
      int num = (int)(s[j] - 'a');
      c[num][i]++;
    }
  }

  REP (i, 30) {
    int minnum = 100;
    REP (j, n) {
      minnum = min(minnum, c[i][j]);
    }
    REP (j, minnum) {
      cout << (char)(i + 'a');
    }
  }
  cout << endl;

  return 0;
}
