#include <bits/stdc++.h>

using namespace std;

const int N = 234567;

int n, a, p[N], r;
vector<pair<int, int> > b;

int main() {

  cin >> n;
  for (int i = 0; i < n; ++i) { cin >> a; b.push_back(make_pair(a, i)); }

  sort(b.begin(), b.end());
  for (int i = 0; i < n; ++i) {
    p[b[i].second] = i;
  }

  for (int i = 0; i < n; ++i) {
    if (p[i] <= n / 2 - 1) { r = b[n / 2].first; }
    else { r = b[n / 2 - 1].first; }  
    cout << r << endl;
  }
  
  return 0;
}