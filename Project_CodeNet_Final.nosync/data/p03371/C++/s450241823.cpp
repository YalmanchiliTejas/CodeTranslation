#include <bits/stdc++.h>
#define dum(x) cout<<#x<<'='<<x<<endl
#define ll long long
using namespace std;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans = 1000000000;
  for (int i = 0; i <= 200000; i+= 2) {
    int tmp = i * c + max(0, x - i / 2) * a + max(0, y - i / 2) * b;
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}
