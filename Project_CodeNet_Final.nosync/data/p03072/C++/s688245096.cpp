#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  rep(i,N) cin >> H[i];
  int ans = 1;
  for (int i = 1; i < N; ++i) {
    bool ok = true;
    for (int j = 0; j < i; ++j) {
      if (H[j] > H[i]) ok = false;
    }
    if (ok) ++ans;
  }
  cout << ans << endl;
  return 0;
}