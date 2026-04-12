#include <algorithm>
#include <deque>
#include <iostream>
#include <type_traits>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  deque<int> colors;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    auto itr = lower_bound(colors.begin(), colors.end(), a);
    if (itr == colors.begin()) {
      colors.push_front(a);
      continue;
    }
    itr--;
    *itr = a;
  }
  cout << colors.size() << endl;
}
