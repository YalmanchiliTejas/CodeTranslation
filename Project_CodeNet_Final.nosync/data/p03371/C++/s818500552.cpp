#include <bits/stdc++.h>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(), (x).end()

using namespace std;

template <typename T> T &chmin(T &a, const T &b) {return a = min(a, b);}
template <typename T> T &chmax(T &a, const T &b) {return a = max(a, b);}

using ll = long long;
using ld = long double;

const int INF = 1e9;
const ld eps = 1e-9, pi = acos(-1.0);

int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  if(a+b<2*c) { cout << a*x+b*y << endl; return 0; }
  int res = c*2*(min(x, y));
  if(x>y) res+=((a>2*c) ? 2*c*(x-y) : a*(x-y));
  else res+=((b>2*c) ? 2*c*(y-x) : b*(y-x));
  cout << res << endl;
  return 0;
}