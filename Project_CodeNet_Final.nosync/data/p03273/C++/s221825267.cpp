#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ALL(v) (v).begin(), (v).end()
#define PR pair<int, int>
#define ios() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
//constexpr int MOD = 10e9+7;
constexpr int INF = 1LL << 60;
inline int in() {int x; cin >> x; return x;}
template <typename T> inline void out(const T& x) {cout << x << endl;}
template <class T> inline bool chmin(T &a, T b){if (a > b){a = b;return 1;}return 0;}
template <class T> inline bool chmax(T &a, T b){if (a < b){a = b;return 1;}return 0;}
//UP = 0;RIGHT = 1; DOWN = 2; LEFT =3;
const int dx[] = {0, 1, 0, -1, 1, -1, 1, -1}, dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
int gcd(int a, int b)
{
  if (a < b)
    gcd(b, a);
  int r;
  while ((r = a % b))
  {
    a = b;
    b = r;
  }
  return b;
}
void eratos(bool * isPrime,int max){
  fill(isPrime,isPrime + max,true);
  isPrime[0] = false; 
  isPrime[1] = false; 
  for(int i=2; i<=max/i; ++i) 
      if(isPrime[i]) 
          for(int j=2; j<=max/i; ++j) 
              isPrime[i*j] = false;    
}
//

signed main()
{
  ios();
  int H,W;
  cin >> H >> W;
  char a[H][W];
  rep(i,H)rep(j,W) cin >> a[i][j];
  bool eraseC[H];
  bool eraseR[W];
  rep(i,H) eraseC[i] = true;
  rep(i,W) eraseR[i] = true;
  rep(i,H)
  {
    rep(j,W)
    {
      if(a[i][j] == '#')
      {
        eraseC[i] = false;
        break;
      }
    }
  }
  rep(j,W)
  {
    rep(i,H)
    {
      if(a[i][j] == '#')
      {
        eraseR[j] = false;
        break;
      }
    }
  }
  rep(i,H)
  {
    if(eraseC[i]) continue;
    rep(j,W)
    {
      if(eraseR[j]) continue;
      cout << a[i][j]; 
    }
    cout << endl;
  }
}
