#include <bits/stdc++.h>
#define ALL(a) (a).begin(), (a).end()
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> v;
  REP(i, n) {
    int a;
    cin >> a;
    int b = upper_bound(ALL(v), a, [](int l, int r) { return l > r; }) - v.begin();
    if (b == v.size()) v.push_back(a);
    else v[b] = a;
  }
  cout << v.size() << endl;
  return 0;
}