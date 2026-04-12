#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const ll INF = 1LL<<29;
const ll mod = 1e9+7;

#define rep(i, a, b) for(ll (i) = (a); (i) < (b);++i)

int main()
{
  ll A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  ll ans = 0;
  if (A + B > C * 2){
    ans += min(X, Y) * 2 * C;
    if (X > Y){
      ans += (X - Y) * A;
    }else{
      ans += (Y - X) * B;
    }
  }else{
    cout << A * X + B * Y << endl;
    return 0;
  }
  if (ans > C * 2 * max(X, Y))
  {
    cout << C * 2 * max(X, Y) << endl;
    return 0;
  }
  cout << ans << endl;
  return 0;
}