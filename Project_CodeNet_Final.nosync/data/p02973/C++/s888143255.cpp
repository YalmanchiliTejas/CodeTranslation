#include <iostream>
#include <set>

#include <vector>
#include <algorithm>

using namespace std;

typedef long long int lli;

int main () {
  int n; cin >> n;
  vector<lli> as(n, 0);
  for (int i = 0; i < n; i++) { cin >> as[i]; }

  int ans = 0;
  multiset<lli> memo;
  for (int i = n - 1; i >= 0; i--) {
    auto it = memo.upper_bound(as[i]);
    if (memo.end() == it) {
      ans++;
    } else {
      memo.erase(it);
    }
    memo.insert(as[i]);
  }
  cout << ans << endl;
}