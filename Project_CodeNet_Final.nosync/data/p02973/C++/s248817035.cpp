#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <type_traits>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> colors;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    auto itr = lower_bound(colors.begin(), colors.end(), a,
                           [](int a, int b) { return a >= b; });
    if (itr == colors.end()) {
      colors.push_back(a);
      continue;
    }
    *itr = a;
  }
  cout << colors.size() << endl;
}
