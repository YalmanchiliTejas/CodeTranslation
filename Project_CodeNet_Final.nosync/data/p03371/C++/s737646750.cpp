#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
static const double EPS = 1e-8;
static const double PI = 4.0 * atan(1.0);
bool ISINT(double x){return fabs(x-(int)round(x))<EPS;}
bool ISEQ(double x,double y){return fabs(x-y)<EPS;}
string itos(ll x){stringstream ss;ss<<x;return ss.str();}
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin();itr!=c.end();itr++)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int A, B, C, X, Y;

  while (cin >> A >> B >> C >> X >> Y) {
    int ans = INT_MAX;
    int mxC = max(X * 2, Y * 2);
    for (int c = 0; c <= mxC; c++) {
      int m = c * C;

      int remX = max(0, X - c / 2);
      int remY = max(0, Y - c / 2);

      m += remX * A + remY * B;
      ans = min(ans, m);
    }
    cout << ans << endl;
  }
}
