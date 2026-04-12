#include <iostream>
#include <algorithm>
using namespace std;

typedef long int lint;
typedef long long int llint;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<long, long> pll;

#define EACH(t, c) for (auto&& t : c)
#define ALL(c) begin(c), end(c)
#define FOR(i, s, e) for (int i = (s); i < (int)(e); ++i)
#define REP(i, n) FOR(i, 0, n)
#define endl '\n'
#define fk first
#define sv second

const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int MOD = (int)1e9 + 7;
const int INF = 999999999;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a, b, c, x, y;

  cin >> a >> b >> c >> x >> y;

  if (x > y) {
    swap(x, y);
    swap(a, b);
  }
  int cost = 0;
  if (a + b > c * 2) {
    cost = x * c * 2;
    y -= x;
    if (b * y < c * y * 2) {
      cost += b * y;
    } else {
      cost += c * y * 2;
    }
  } else {
    cost = a * x + b * y;
  }

  cout << cost << endl;
}