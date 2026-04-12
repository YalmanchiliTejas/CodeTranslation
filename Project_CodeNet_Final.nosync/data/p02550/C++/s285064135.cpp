#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1001001001;

int main() {
  ll n, x, m;
  cin >> n >> x >> m;
  vector<ll> r;
  set<ll> q;
  r.push_back(x);
  q.insert(x);
  while (1) {
    x = (x * x) % m;
    if (q.find(x) != q.end()) {
      ll ans = 0;
      while (r.front() != x) {
        ans += r.front();
        n--;
        r.erase(r.begin());
      }
      ll sum = 0;
      for (auto el : r) {
        sum += el;
      }
      ans += (n / r.size()) * sum;
      rep(i, n % r.size()) ans += r[i];
      cout << ans << endl;
      return 0;
    } else {
      r.push_back(x);
      q.insert(x);
    }
  }

  return 0;
}