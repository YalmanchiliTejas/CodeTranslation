#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <map>
#include <set>
#include <ctype.h>
#include <numeric>
#include <math.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const ll MOD = 1e9 + 7;
const int INF = 1e9;

int dx4[4] = { 0, -1, 1, 0 };
int dy4[4] = { -1, 0, 0, 1 };
int dx8[8] = { 0, -1, 1, 0, -1, 1, -1, 1 };
int dy8[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };

int main() {
  int n; cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; ++i) cin >> h[i];
  int res = 1;
  for (int i = 1; i < n; ++i) {
    bool check = true;
    for (int k = 0; k < i; ++k) {
      if (h[k] > h[i]) {
        check = false;
        break;
      }
    }
    if (check) ++res;
  }

  cout << res << endl;
  return 0;
}
