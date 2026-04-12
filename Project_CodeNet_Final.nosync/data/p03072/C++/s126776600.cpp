#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0, now = 0;
vector<int> h;

int main() {
  cin >> n;
  h.resize(n);
  for(int i = 0; i < n; ++i) cin >> h[i];
  for(int i = 0; i < n; ++i)
    if(h[i] >= now) {
      ++cnt;
      now = h[i];
    }
  cout << cnt << endl;
  return 0;
}