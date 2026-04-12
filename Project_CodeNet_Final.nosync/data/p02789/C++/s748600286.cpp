#include <cstdio>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

int N, M;

int main()
{
  scanf( "%d%d", &N, &M );

  puts( N==M ? "Yes" : "No" );

  return 0;
}