#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

// https://atcoder.jp/contests/abc095/tasks/arc096_a

int main() {
  int a, b, c;
  int x, y;
  cin >> a >> b >> c;
  cin >> x >> y;

  int ans = 0;

  // 1. a,bピザをx,y枚購入する
  {
    int count = a * x + b * y;
    ans = count;
  }
  // 2. min(x,y) a or bピザを購入し、残り*2枚数cピザを購入する
  {
    int count = 0;
    int sub = abs(x - y);
    if(x > y) {
      count = sub * a;
    } else {
      count = sub * b;
    }
    int rest = max(x, y) - sub;
    count += c * rest * 2;
    ans = min(ans, count);
  }
  // 3. cピザをmax(x,y)*2枚購入する
  {
    int count = max(x, y) * 2 * c;
    ans = min(ans, count);
  }
  cout << ans << endl;
  return 0;
}