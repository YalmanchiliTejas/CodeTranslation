#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
typedef unsigned long long u64;
typedef signed long long l64;

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  l64 a[n];
  bool iszero = true;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] >= n) iszero = false;
  }
  if (iszero) {
    cout << 0 << endl;
    return 0;
  }
  u64 now_best;
  for (int j = 0; j < n; ++j) {
    l64 db = -1, dt = (10000000000000000+1000)+1;
    u64 cur = (db+dt)/2;
    while (dt-db != 1) {
      u64 over = 0;
      for (int i = 0; i < n; ++i) {
        if (a[i] + (cur*n+j) > n-1) {
          over += ((a[i] + (cur*n+j) - n) / (n+1)) + 1;
        }
      }
      if (over <= (cur*n+j)) {
        dt = cur;
      } else {
        db = cur;
      }
      cur = (dt+db)/2;
    }
    if (j == 0 || dt*n+j < now_best) {
      now_best = dt*n+j;
    }
  }
  cout << now_best << endl;
  return 0;
}
