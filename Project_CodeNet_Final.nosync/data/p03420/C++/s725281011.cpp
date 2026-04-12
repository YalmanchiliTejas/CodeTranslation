
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
typedef long long ll;

int main(void) {
  ll n, k;
  cin >> n >> k;
  ll res = n*n;
  // cerr << res << endl;
  if(k > 0) {
    for(int b = 1; b <= n; ++b) {
      res -= n/b*min(k, (ll)b);
      int tmp = n%b;
      res -= k > tmp ? tmp : k-1;
      // cerr << res << endl;
    }
  }
  cout << res << endl;
  return 0;
}
