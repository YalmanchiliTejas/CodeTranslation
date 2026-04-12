#include <bits/stdc++.h>
using namespace std;
#define SORT(a) sort((a).begin(), (a).end())
#define RSORT(a) reverse((a).begin(), (a).end())
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(a) ((a).begin(), (a).end())
typedef long long ll;
// const long long INF = 1LL << 60;
const int INF = 1010101010;
// using Graph = vector<vector<int>>;
const int MOD = 1000000007;

int main() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  multiset<ll> s;

  for (ll i = 0; i < n; ++i) {
    ll now = a[i];
    auto itr = s.lower_bound(now);
    if (itr != s.begin()) s.erase(--itr);
    s.insert(now);
  }
  cout << s.size() << endl;
  return 0;
}