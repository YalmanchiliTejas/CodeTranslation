#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
constexpr int kMod = 1000000007;
typedef long long LL;

std::map<char, int> countup(std::string S) {
  std::map<char, int> cnt;
  for (char c : S) {
    ++cnt[c];
  }
  return cnt;
}

int main() {
  int N; std::cin >> N;
  int ans[26];
  for (int i = 0; i < 26; ++i) ans[i] = INT_MAX;

  for (int n = 0; n < N; ++n) {
    int cnt[26] = {};
    std::string S; std::cin >> S;
    for (char c : S) {
      ++cnt[c - 'a'];
    }

    for (int i = 0; i < 26; ++i) {
      ans[i] = std::min(ans[i], cnt[i]);
    }
  }

  for (int i = 0; i < 26; ++i) {
    char c = 'a' + i;
    for (int k = 0; k < ans[i]; ++k) std::cout << c;
  }
  std::cout << std::endl;
}
