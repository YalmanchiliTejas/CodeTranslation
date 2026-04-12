#include <cstdio>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int r, g, b;

int main()
{
  scanf( "%d%d%d", &r, &g, &b );

  puts( (100*r+10*g+b)%4 ? "NO" : "YES" );

  return 0;
}