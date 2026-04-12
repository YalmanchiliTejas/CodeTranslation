#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

multiset<long long> vals;

int n;

long long mMax = 0, mMin = (1 << 30) - 1;

vector<pair<long long, long long>> s;

long long curProd(int removed) {
  return (max(mMax, s[s.size() - 1].first) - min(mMin, s[removed].first)) * ((*(--vals.end())) - (*vals.begin()));
}

int main() {
  cin >> n;

  for (int i = 1 ; i <= n; ++i) {
    long long x, y;
    cin >> x >> y;
    if (x < y)
      swap(x, y);
    vals.insert(x);
    s.push_back(make_pair(y, x));
  }

  sort(s.begin(), s.end());

  long long bestProd = curProd(0);

  for (int removed = 0; removed < n; ++removed) {
    vals.insert(s[removed].first);
    mMin = min(mMin, s[removed].second);
    mMax = max(mMax, s[removed].second);
    bestProd = min(bestProd, curProd(removed + 1));
  }

  cout << bestProd;
  return 0;
}
