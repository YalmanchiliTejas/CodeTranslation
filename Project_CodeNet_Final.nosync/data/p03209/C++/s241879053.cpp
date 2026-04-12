#include <algorithm>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>


using namespace std;

typedef long long ll;


class Solution {
 public:
  void solve(std::istream& in, std::ostream& out) {
    ll n, x;
    in >> n >> x;
    ll dp[51][2];
    dp[0][0] = dp[0][1] = 1;
    for (int ctr1 = 1; ctr1 < 51; ++ctr1) {
      dp[ctr1][0] = 1 + 2 * dp[ctr1 - 1][0];
      dp[ctr1][1] = 3 + 2 * dp[ctr1 - 1][1];
    }
    ll rez = 0;
    for (int ctr1 = n; ctr1 >= 0; --ctr1) {
      if (x == dp[ctr1][1]) {
        rez += dp[ctr1][0];
        x = 0;
      } else if (x > dp[ctr1][1] / 2) {
        rez += 1 + (ctr1 > 0 ? dp[ctr1 - 1][0] : 0);
        x -= 1 + dp[ctr1][1] / 2;
      } else {
        --x;
      }
    }
    out << rez;
  }
};

void solve(std::istream& in, std::ostream& out)
{
  out << std::setprecision(12);
  Solution solution;
  solution.solve(in, out);
}
// Powered by caide (code generator, tester, and library code inliner)


#include <fstream>
#include <iostream>


int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(0);


  istream& in = cin;


  ostream& out = cout;

  solve(in, out);
  return 0;
}

