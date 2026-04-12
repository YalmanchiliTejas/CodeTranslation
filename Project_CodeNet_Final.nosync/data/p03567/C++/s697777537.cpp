#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  string s;
  cin >> s;
  bool ac = false;
  for (int i = 0; i < s.size(); i++) {
    if (i + 1 < s.size() && s[i] == 'A' && s[i + 1] == 'C') {
      ac = true;
      break;
    }
  }
  string ans = (ac) ? "Yes" : "No";
  cout << ans << endl;
  return 0;
}