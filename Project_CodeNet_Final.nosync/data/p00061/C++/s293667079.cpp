#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<pair<int, int> > v;
  int p, s;
  while (scanf("%d,%d", &p, &s), p + s) {
    v.push_back(make_pair(s, p));
  }

  sort(v.begin(), v.end(), greater<pair<int, int> >());

  vector<int> rank(101, 1);
  int r = 1;
  for (int i = 1; i < v.size(); ++i) {
    if (v[i].first != v[i - 1].first) r++;
    rank[v[i].second] = r;
  }

  int q;
  while (cin >> q) {
    cout << rank[q] << endl;
  }
}