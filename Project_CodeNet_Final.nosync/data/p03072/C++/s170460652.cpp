#include <cstdio>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

int N;
int H[30];

int main()
{
  scanf( "%d", &N );
  rep( i, N )
    scanf( "%d", H+i );

  int ma = 0, ans = 0;
  rep( i, N )
  {
    if( ma <= H[i] )
    {
      ++ans;
      ma = H[i];
    }
  }

  printf( "%d\n", ans );

  return 0;
}