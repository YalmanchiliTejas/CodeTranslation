#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  int x, m;
  cin >> x >> m;
  long long ans = x;
  --n;
  long long cur = (x * x) % m;
  long long sum = 0;
  vector<int> seen(m), res(m), val(m + 2);
  int pos = 1;
  while (n && !seen[cur]) {
    // cout << cur << ' ';
    sum += cur;
    seen[cur] = pos;
    res[cur] = sum;
    val[pos] = sum;
    cur = (cur * cur) % m;
    --n;
    if (n == 0) {
      cout << sum + x << '\n';
      return 0;
    }
    ++pos;
  }   
  // cout << "\n";
  // cout << cur << '\n';
  // cout << "sum: " << sum << '\n';
  int cycle = pos - seen[cur];
  int rep = sum - val[seen[cur] - 1];
  // cout << rep << '\n';
  sum += rep * (n / cycle);
  // cout << "cycle: " << cycle << '\n';
  // cout << n / cycle << '\n';
  // cout << "sum: " << sum << '\n';
  int rem = n % cycle;
  // cout << "rem: " << rem << '\n';
  if (rem) {
    // cout << val[seen[cur] + rem - 1] - val[seen[cur] - 1] << '\n'; 
    sum += val[seen[cur] + rem - 1] - val[seen[cur] - 1];
  }
  cout << sum + x << '\n';
  return 0;
}