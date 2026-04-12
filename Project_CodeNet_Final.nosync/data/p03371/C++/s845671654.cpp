#include <algorithm>  // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <bitset>     // bitset
#include <cctype>     // isupper, islower, isdigit, toupper, tolower
#include <cstdint>    // int64_t, int*_t
#include <cstdio>     // printf
#include <deque>      // deque
#include <iomanip>    // fixed, setprecision
#include <iostream>   // cout, endl, cin
#include <map>        // map
#include <numeric>    // accumulate
#include <queue>      // queue, priority_queue
#include <set>        // set
#include <stack>      // stack
#include <string>     // string, to_string, stoi
#include <tuple>      // tuple, make_tuple
#include <unordered_map>  // unordered_map
#include <unordered_set>  // unordered_set
#include <utility>        // pair, make_pair
#include <vector>         // vector
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
  int A, B, C, X, Y, a, b, c, d, e;
  cin >> A >> B >> C >> X >> Y;
  a = C * 2 * max(X, Y);
  b = A * X + B * Y;
  // c = max(0, X - Y) * C * 2 + max(0, Y - X) * B;
  // d = max(0, X - Y) * A + max(0, Y - X) * C * 2;
  e = min(X, Y) * C * 2 + max(0, Y - X) * B + max(0, X - Y) * A;

  cout << min(a, min(b, e)) << endl;
}
