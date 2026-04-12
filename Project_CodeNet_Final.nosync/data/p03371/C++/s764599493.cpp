#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define REP(i, n) for(int i = 0; i < (n); i++)
#define ALL(c) c.begin(),c.end()
#define PB push_back

using namespace std;
typedef long long ll;

int main()
{
  ll A, B, C;
  cin >> A >> B >> C;
  ll X, Y;
  cin >> X >> Y;
  if (A + B <= 2*C) cout << (A*X + B*Y) << endl;
  else {
    ll ans = 0;
    ll m = min(X, Y);
    ans += 2*C*m;
    X -= m, Y -= m;
    if (X > 0 && A <= 2*C) ans += A*X;
    else if (Y > 0 && B <= 2*C) ans += B*Y;
    else ans += 2*C*(X + Y);
    cout << ans << endl;
  }

  return 0;
}