#include <vector>
#include <iostream>

using namespace std;

#define int long long

const int N = 2e5 + 10;

int ok[N];

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);    
  int n;
  cin >> n;
  int x, m;
  cin >> x >> m;
  vector<int> v;
  int ans = 0;
  for (int i = x;; i = (i * i) % m) {
    if (++ok[i] == 2) {
      break;
    }
    ans += i;
    v.push_back(i);
  }
  int i = 0;
  while (ok[v[i]] != 2) {
    ++i;
  }
  for (int j = i; j < v.size(); ++j) {
    ans += v[j] * ((n - i) / (v.size() - i));
    ans -= v[j];
  }
  for (int j = i; j < i + ((n - i) % (v.size() - i)); ++j) {
    ans += v[j];
  }
  cout << ans;
  return 0;
}
