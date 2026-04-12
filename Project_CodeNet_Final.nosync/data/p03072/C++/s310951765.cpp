#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
  int n;
  int ans = 0;
  cin >> n;
  vector<int> h(n);

  for (int i=0; i<n; i++) cin>>h[i];
  int hmax = -1;
  for (int i=0; i<n; i++) {
    if (hmax <= h[i]) ans++;
    hmax = max( hmax, h[i]);
  }

  cout << ans << endl;
}
