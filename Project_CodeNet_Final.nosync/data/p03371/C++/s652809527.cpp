#include <iostream>
#include <cmath>
using namespace std;

const int INF = pow(2, 31) - 1;
#define ll long long
#define DEBUG(x) cout << "DEBUG>" << #x << ":" << x << endl;
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  ll ans = 2 * max(X, Y) * C + X * A + Y * B;
  FOR(i, 0, max(X, Y)) {
    ll cost = 2 * i * C + max((ll)0, (X - i)) * A + max((ll)0, (Y - i)) * B;
    ans = min(ans, cost);
  }
  cout << ans << endl;
  return 0;
}
