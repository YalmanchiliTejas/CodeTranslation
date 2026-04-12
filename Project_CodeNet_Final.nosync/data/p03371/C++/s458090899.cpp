// https://atcoder.jp/contests/abc095/tasks/arc096_a

#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

using ll = long long;

int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  long long ans = ll(1e9)+1;
  for(int i = 0; i < max(x, y) + 1; i++){
    long long tmp = 0;
    tmp += 1ll * c * i * 2;
    tmp += 1ll * max(0, x - i) * a;
    tmp += 1ll * max(0, y - i) * b;
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}
