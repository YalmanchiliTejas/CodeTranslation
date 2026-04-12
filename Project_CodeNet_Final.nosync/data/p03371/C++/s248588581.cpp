#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int main() {
  ll A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  ll mn = 10e10;
  REP(i, 300000) {
    ll num = 0;
    num += C * i;
    if (i / 2 < X) {
      num += (X - i / 2) * A;
    }
    if (i / 2 < Y) {
      num += (Y - i / 2) * B;
    }
    mn = min(num, mn);
  }
  cout << mn << endl;
}