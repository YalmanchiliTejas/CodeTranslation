#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;
using Graph = vector<vector<int>>;

// int main() {
//   int a, b, c;
//   int x, y;
//   cin >> a >> b >> c >> x >> y;

//   int n = a * x + b * y;

//   int m = 2 * c * max(x, y);

//   int p = x < y ? b : a;
//   int l = 2 * c * min(x, y) + p * abs(x - y);

//   int ans = min(n, min(m, l));
//   cout << ans << endl;

//   return 0;
// }


int main() {
  int a, b, c;
  int x, y;
  cin >> a >> b >> c >> x >> y;
  int ans = a*x + b*y;

  for (int i = 0; i < max(x, y)+1; i++) {
    ans = min(ans,max(0, x-i)*a + max(0, y-i)*b + 2*i*c);
  }

  cout << ans << endl;

  return 0;
}