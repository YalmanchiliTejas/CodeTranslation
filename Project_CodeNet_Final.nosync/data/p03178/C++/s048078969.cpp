#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
Tutorials:
  * https://discuss.codechef.com/questions/83102/workchef-unofficial-editorial
  * https://stackoverflow.com/questions/22394257/how-to-count-integers-between-large-a-and-b-with-a-certain-property/22394258#22394258 (really good)
*/

int D;
string X;
const int MOD = 1e9 + 7;
struct State {
  string X;
  int sum_so_far;
  string acc;

  int dig(const int i) const {
    return X[i] - '0';
  }
};

long long count(State state, int i, int leftmost_lo, int leftmost_hi) {
  if (i == state.X.length()) {
    //cout << state.X.length()<< " " << state.sum_so_far << "  " << state.acc << "\n";
    if (state.sum_so_far == 0 && leftmost_lo <= leftmost_hi) {
      cout << state.acc << " " << state.sum_so_far << "\n";
      return 1;
    } else {
      return 0;
    }
  }
  long long ans = 0;
  for (int d = 0; d <= 9; d++) {
    int leftmost_lo_prime = d < state.dig(i) && i < leftmost_lo? i : leftmost_lo;
    int leftmost_hi_prime = d > state.dig(i) && i < leftmost_hi? i : leftmost_hi;
    state.sum_so_far = (state.sum_so_far + d) % D;
    state.acc += to_string(d);
    ans += count(state, i + 1, leftmost_lo_prime, leftmost_hi_prime);
    state.acc = state.acc.substr(0, state.acc.length() - 1);
    state.sum_so_far -= d;
  }
  return ans;
}
vector<vector<vector<long long>>>dp;
long long count(int i, int sum_so_far, bool lo) {
  if (i == X.length()) {
    return sum_so_far % D == 0;
  }
  if (dp[i][sum_so_far][lo] != -1) return dp[i][sum_so_far][lo];
  long long ans = 0;
  for (int d = 0; d <= (lo ? 9 : (X[i] - '0')); d++) {
    ans = (ans + count(i + 1, (sum_so_far + d) % D, lo || d < (X[i] - '0'))) % MOD;
  }
  return dp[i][sum_so_far][lo] = ans;
}

int main() {
  //D = 4;
  //State state = { "30", 0, "" };
  cin >> X >> D;
  int n = X.length();
  dp.clear();
  dp.resize(n, vector<vector<long long>>(D, vector<long long>(2, -1)));
  
  int ans = count(0, 0, false) - 1;
  if (ans < 0) ans = MOD - 1;
  cout << ans << "\n";
  return 0;
}