#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main() {
  int a[101] = {}, q;
  while (true) {
    int p, s;
    char c;
    cin >> p >> c >> s;
    if (p == 0 && s == 0)
      break;
    a[p] = s;
  }

  pair<int, int> b[101] = {make_pair(-1, -1)};
  for (int i = 1; i <= 100; ++i)
    b[i] = make_pair(a[i], i);
  sort(b, b + 101, greater<pair<int, int>>());

  int rank[101] = {}, s = 31, r = 0;
  for (int i = 0; i < 100; ++i) {
    if (b[i].first < s)
      ++r, rank[b[i].second] = r, s = b[i].first;
    else
      rank[b[i].second] = r;
  }

  while (cin >> q)
    cout << rank[q] << endl;
}
