#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;
typedef long long ll;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define DEC(i, s) for (int i = (s); i >= 0; i--)

#define SIZE(v) (int)((v).size())
#define MEMSET(v, h) memset((v), h, sizeof(v))
#define FIND(m, w) ((m).find(w) != (m).end())

int main() {
  int test;
  cin >> test;
  while (test--) {
    ll first;
    cin >> first;
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    REP(i, m) {
      ll o, c;
      double rate;
      cin >> o >> rate >> c;
      ll num = first;
      REP(j, n) {
        if (o == 0) {
          num += (first - c * j) * rate;
          num -= c;
          if (num <= 0) { break; }
        } else if (o == 1) {
          num += num * rate;
          num -= c;
          if (num <= 0) { break; }
        }
      }
      ans = max(ans, num);
    }
    cout << ans << endl;
  }
}