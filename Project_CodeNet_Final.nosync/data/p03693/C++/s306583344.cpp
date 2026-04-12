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
  ll r, g, b;
  cin >> r >> g >> b;
  ll num = 100 * r + 10 * g + b;
  if (num % 4 == 0) {
    cout << "YES" << endl;
  } else
    cout << "NO" << endl;
  return 0;
}