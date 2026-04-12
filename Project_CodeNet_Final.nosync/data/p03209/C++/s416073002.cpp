#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define _GLIBCXX_DEBUG

int P(int n, int x) {
  int preso = pow(2,n+1) - 3;
  if(n == 0) return 1;
  if(x >= preso*2+3) return 2*P(n-1, preso) + 1;
  else if(x >= preso+3) return P(n-1, preso) + P(n-1, x-preso-2) + 1;
  else if(x == preso+2) return P(n-1, preso) + 1;
  else if(x >= 2) return P(n-1, x-1);
  else return 0;
}

signed main() {
  int N, X; cin >> N >> X;
  if(X == 1) {
    cout << 0 << endl;
    return 0;
  }
  
  cout << P(N, X) << endl;
  


}