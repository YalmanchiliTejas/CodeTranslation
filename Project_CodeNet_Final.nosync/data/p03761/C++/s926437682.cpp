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
  std::string S; std::cin >> S;
  std::map<char, int> ret = countup(S);
  for (int i = 1; i < N; ++i) {
    std::cin >> S;
    std::map<char, int> tmp = countup(S);
    for (auto p : ret) {
      char ch = p.first;
      int cnt = p.second;
      if (tmp.find(ch) != tmp.end()) {
        ret[ch] = std::min(ret[ch], tmp[ch]);
      } else {
        ret[ch] = 0;
      }
    }
  }

  for (auto p : ret) {
    for (int i = 0; i < p.second; ++i) std::cout << p.first;
  }
  std::cout << std::endl;
}
