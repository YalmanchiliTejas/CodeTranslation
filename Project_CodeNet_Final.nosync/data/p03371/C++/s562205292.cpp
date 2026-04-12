#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;
static const int INF = 2000000000;

int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans = 0;
  if ((a + b) <= 2 * c){
    ans += a * x + b * y;
  } else {
    ans += 2 * c * min(x, y);
    if (x > y){
      int z = x - y;
      if (a <= 2*c) ans += a * z;
      else ans += 2*c * z;
    }
    else if (y > x){
      int z = y - x;
      if (b <= 2*c) ans += b * z;
      else ans += 2*c * z;
    }
  }
  cout << ans << endl;
}
