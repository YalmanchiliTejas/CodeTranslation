#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define repr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
const ll mod = 1e9 + 7;

int main() {
  int n, w;
  cin >> n >> w;
  if (n == w)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
