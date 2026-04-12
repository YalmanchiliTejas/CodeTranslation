#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll x, y, z;
  cin >> x >> y >> z;
  ll ans = (x - z) / (y + z);
  cout << ans << endl;
  return 0;
}