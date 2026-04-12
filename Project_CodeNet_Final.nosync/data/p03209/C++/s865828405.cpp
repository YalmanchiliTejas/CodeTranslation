#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

long long n, x;
vector<long long> bps, ps;
long long cnt=0, ans=0;

void rec(int l) {
  if (l == 0) {
    ans++;
    if(--x <= 0) return;
  } else {
    if(x - bps[l] >= 0) {
      ans += ps[l];
      x -= bps[l];
      if (x == 0) return;
    } else {
      if(--x <= 0) return; // b
      rec(l-1);
      if(x <= 0) return;
      ans++;
      if(--x <= 0) return; // p
      rec(l-1);
      if(--x <= 0) return; // b
    }
  }
}

int main() {
  cin >> n >> x;
  bps = vector<long long>(51);
  ps = vector<long long>(51);
  bps[0] = 1;
  ps[0] = 1;
  for (int i=1; i<=n; ++i) {
    bps[i] = 3 + 2*bps[i-1];
    ps[i] = 1 + 2*ps[i-1];
  }
  rec(n);
  cout << ans << endl;
  return 0;
}
