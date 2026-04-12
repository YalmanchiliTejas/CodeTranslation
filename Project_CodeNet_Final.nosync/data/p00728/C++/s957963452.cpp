#include <iostream>
#include <iomanip>
#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

typedef long long          ll;
typedef unsigned int       uint;
typedef unsigned long long ull;

using namespace std;

int main() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0) {
      break;
    }
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    sort(s.begin(), s.end());
    std::cout << accumulate(s.begin() + 1, s.end() - 1, 0) / (s.size() - 2) << std::endl;
  }
}