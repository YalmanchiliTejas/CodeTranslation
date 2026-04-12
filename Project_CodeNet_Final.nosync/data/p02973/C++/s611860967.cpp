#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(var, begin, end) for (int var = (begin); i < (end); i++)
#define RFOR(var, begin, end) for (int var = (begin) - 1; i >= (end); i--)
#define REP(var, length) FOR(var, 0, length)
#define RREP(var, length) RFOR(var, length, 0)
#define SORT(vector) sort(vector.begin(), vector.end())

const ll MOD = 1e9 + 7;

void solve(istream& cin, ostream& cout) {
  int n, a;
  cin >> n;
  multiset<int> c{-1};
  REP(i, n) {
    cin >> a;
    auto itr = c.lower_bound(a);
    if (itr == c.begin()) {
      c.insert(a);
    } else {
      itr--;
      c.erase(itr);
      c.insert(a);
    }
  }
  
  cout << c.size() << endl;
}

#ifndef TEST
int main() {
  solve(cin, cout);
}
#endif
