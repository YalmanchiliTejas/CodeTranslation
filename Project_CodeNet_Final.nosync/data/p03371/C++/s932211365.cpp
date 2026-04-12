#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define INF 1999999999
#define MODA 1000000007 
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main() {
  ll A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  ll ans = 0;
  if (2*C < A+B) {
    ans += 2*C*min(X,Y);
  }
  else {
    ans += (A+B)*min(X,Y);
  }
  if(X > Y) {
    if(A < 2*C) ans += A*(X-Y);
    else ans += 2*C*(X-Y);
  }
  else {
    if(B < 2*C) ans += B*(Y-X);
    else ans += 2*C*(Y-X);
  }
  cout << ans << endl;

  return 0;
}
