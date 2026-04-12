#include <math.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;
using Graph = vector<vector<int>>;

using ll = long long;
typedef pair<ll, ll> P_ll;
typedef pair<int, int> P;

const ll INF_ll = 1e17;
const int INF = 1e8;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  ll ans = 0;
  int min_AB = min(A + B, 2 * C);

  if (X > Y) {
    ans += Y * min_AB;
    if (A > 2 * C) {
      ans += (X - Y) * 2 * C;
    } else {
      ans += (X - Y) * A;
    }
  } else {
    ans += X * min_AB;
    if (B > 2 * C) {
      ans += (Y - X) * 2 * C;
    } else {
      ans += (Y - X) * B;
    }
  }
  cout << ans << endl;

  return 0;
}