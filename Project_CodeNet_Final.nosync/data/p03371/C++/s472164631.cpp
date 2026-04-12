#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i >= 0; i--)
#define REP(i, m, n) for (int i = (int)(m); i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;

int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  int res = 1001001001;
  if(x <= y){
    chmin(res, c * y * 2);
    chmin(res, c * x * 2 + b * (y-x));
    chmin(res, a * x + b * y);
  }
  if(x > y){
    chmin(res, c * x * 2);
    chmin(res, c * y * 2 + a * (x-y));
    chmin(res, a * x + b * y);
  }

  cout << res << endl;

  return 0;
}
