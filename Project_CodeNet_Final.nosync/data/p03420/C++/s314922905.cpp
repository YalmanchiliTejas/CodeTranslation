#include <bits/stdc++.h>
using namespace std;


int main() {
  int n,k;
  int64_t cnt = 0;
  cin >> n >> k;
  if(k != 0) {
  for (int b = max(1,k); b < n+1; b++) {
    if (n%b < k) {
      cnt += (n/b) * (b-k);
    }
    else if (n%b >= k) {
      cnt += (n/b) * (b-k) + (n%b - k + 1);
    }
  }
  }
  else if (k == 0) {
    for (int b = max(1,k); b < n+1; b++) {
    if (n%b < k) {
      cnt += (n/b) * (b-k);
    }
    else if (n%b >= k) {
      cnt += (n/b) * (b-k) + (n%b - k);
    }
  }
  }
  cout << cnt << endl;
}