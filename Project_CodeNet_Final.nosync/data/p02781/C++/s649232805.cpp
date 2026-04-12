#include <iostream>
#include <vector>

using namespace std;

using Memo = vector<vector<vector<int>>>;

long long solve(string &s, int offset, bool is_less, int nonzero_cnt, Memo &memo) {
  if (offset == s.size()) {
    return nonzero_cnt == 0 ? 1 : 0; 
  } else if (nonzero_cnt < 0) {
    return 0;
  }

  if (memo[offset][is_less][nonzero_cnt] < 0) {
    int digit = s[offset] - '0';
    long long ans = 0;
    for (int i = 0; i <= (is_less ? 9 : digit); i++) {
      ans += solve(s, offset + 1, is_less || i < digit, i != 0 ? nonzero_cnt - 1 : nonzero_cnt, memo);
    }

    memo[offset][is_less][nonzero_cnt] = ans;
  }

  return memo[offset][is_less][nonzero_cnt];
}

int main(int argc, const char *argv[])
{
  string n;
  int k;
  cin >> n >> k;

  Memo memo(n.size() + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));
  cout << solve(n, 0, false, k, memo) << "\n";
  return 0;
}