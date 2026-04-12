#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
  fastIO;
  int n;
  cin >> n;

  vector<int>H(n);
  rep(i, n) cin >> H.at(i);

  int cnt = 1;
  int maxH = H.at(0);

  for(size_t i=1; i<H.size(); ++i) {
    if(H.at(i) >= maxH) {
      cnt++;
    }
    maxH = max(maxH, H.at(i));
  }
  cout << cnt << endl;
}
