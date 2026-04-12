#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 10e17
#define rep(i,n) for(long long i=0; i<n; i++)
#define repr(i,n,m) for(long long i=m; i<n; i++)
#define mod 1000000007
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<long long>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto&& itr : x) { cerr << (itr) << " "; }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  int total = a * x + b * y;
  while (true) {
    if (y > 0 || x > 0) {
      auto t = total;
      if (x > 0) t -= a;
      if (y > 0) t -= b;
      if (t + c * 2 < total) {
        total = t + c * 2;
        x --, y --;
      } else {
        break;
      }
    } else {
      break;
    }
  }
  // cout << x << " " << y << endl;

  cout << total << endl;
}