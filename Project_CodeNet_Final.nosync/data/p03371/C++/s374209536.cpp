#include <bits/stdc++.h>
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
using namespace std;

int main() {
  int A,B,C,X,Y,Z;
  int ans=1e9;
  cin >> A >> B >> C >> X >> Y;
  rep(i, 100001) {
    int sum = 0;
    sum += i*2*C;
    sum += max(0, X-i) * A;
    sum += max(0, Y-i) * B;
    ans = min(ans, sum);
  }
  cout << ans << endl;
  return 0;
}
