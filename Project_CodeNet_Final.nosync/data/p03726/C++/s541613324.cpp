#include <bits/stdc++.h>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/adaptor/indexed.hpp>

using namespace std;
using namespace boost::adaptors;
using namespace std::string_literals;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;
using boost::irange;

tuple<bool, bool> dfs(const vector<vecint>& g, int i, int p=-1) {
  int lcnt = 0;
  for (auto&& to : g[i]) {
    if (to == p) continue;
    bool win, isl;
    tie(win, isl) = dfs(g, to, i);
    if (win) return make_tuple(true, false);
    if (isl) ++lcnt;
  }
  if (lcnt >= 2) return make_tuple(true, false);
  else if (lcnt == 1) return make_tuple(false, false);
  else return make_tuple(false, true);
}

int main()
{
  int n;
  cin>>n;
  vector<vecint> g(n);
  for(int i:irange(0,n-1)) {
    int a,b;
    cin>>a>>b;
    --a;--b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  bool win, isl;
  tie(win, isl) = dfs(g, 0);
  win = win || isl;
  if (win) {
    cout<<"First\n";
  } else {
    cout<<"Second\n";
  }
  return 0;
}
