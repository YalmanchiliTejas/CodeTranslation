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

int main() {
  int N; std::cin >> N;
  std::vector<int> m;
  for (int i = 0; i < N; ++i) {
    int a; std::cin >> a;

    if (!m.empty() && m.back() < a) {
      for (int& v : m) {
        if (v < a) {
          v = a;
          break;
        }
      }
    } else {
      m.push_back(a);
    }
  }

  std::cout << m.size() << std::endl;
}
