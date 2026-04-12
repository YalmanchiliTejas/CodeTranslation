#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))

int main() {
  int n, ans, max; ans = 1;
  cin >> n;
  vector<int> h(n);

  rep(i, n) {
    cin >> h[i];
  }

  max = h[0];
  rep(i, n-1) {
    if (h[i+1] >= max) {
      max = h[i+1];
      ans++;
    }
  } 

  cout << ans << endl;
}