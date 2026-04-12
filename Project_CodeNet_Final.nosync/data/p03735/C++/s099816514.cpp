#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) ( (int)(x).size() )
using LL = long long;

template<class T>
inline bool asMn(T &a, const T &b) { return a > b ? a = b, true : false; }
template<class T>
inline bool asMx(T &a, const T &b) { return a < b ? a = b, true : false; }

const int inf = 1e9 + 7;
const LL infLL = 1e18 + 100;
mt19937 rng( (uint32_t)chrono::steady_clock::now().time_since_epoch().count() );

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  #ifdef FourLeafClover
  freopen("input", "r", stdin);
  #endif // FourLeafCLover

  int n; cin >> n;
  vector<pair<int, int> > a(n);
  vector<int> com;
  int lim = inf;
  for (auto &i : a) {
    cin >> i.first >> i.second;
    if (i.first > i.second) swap(i.first, i.second);
    com.emplace_back(i.first);
    com.emplace_back(i.second);
    asMn(lim, i.second);
  }
  sort(all(com) ); com.erase(unique(all(com) ), com.end() );

  multiset<int> r, b;
  for (const auto &i : a) {
    r.emplace(i.second);
    b.emplace(i.first);
  }

  vector<int> sorI(n); iota(all(sorI), 0);
  sort(all(sorI), [&](const int &i, const int &j) {
       return a[i].first < a[j].first;
       });
  LL ans = infLL;
  for (const auto &mnB : com) {
    if (mnB > lim) break ;
    static auto i = sorI.begin();
    while (i != sorI.end() && a[*i].first < mnB) {
      r.erase(r.find(a[*i].second) ); r.emplace(a[*i].first);
      b.erase(b.find(a[*i].first) ); b.emplace(a[*i].second);
      ++i;
    }
    asMn(ans, (LL)(*r.rbegin() - *r.begin() ) * (*b.rbegin() - *b.begin() ) );
  }

  cout << ans << '\n';

  return 0;
}
