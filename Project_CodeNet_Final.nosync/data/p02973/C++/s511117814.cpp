#include <bits/stdc++.h>

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

signed main() {
  ll N;
  cin>>N;
  vector<ll> a(N);
  rep(i,0,N)
    cin>>a[i];

  multiset<ll> s; // 各色の最小値
  for (int i=N-1; i>=0; i--) {
    auto it = s.upper_bound(a[i]);
    if (it != s.end()) {
      s.erase(it);
      s.insert(a[i]);
    } else {
      s.insert(a[i]);
    }
  }
  cout<<s.size()<<endl;
}
