#include <cstdio>
#include <algorithm>
#include <vector>
#include <numeric>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

int N, M;
bool adj[10][10];
int ans;

int main()
{
  scanf( "%d%d", &N, &M );
  rep( i, M )
  {
    int a, b;
    scanf( "%d%d", &a, &b );
    --a; --b;
    adj[a][b] = adj[b][a] = true;
  }

  std::vector<int> perm( N-1 );
  std::iota( all(perm), 1 );

  do
  {
    bool fl = true;

    rep( i, N-1 )
    {
      int prv = i ? perm[i-1] : 0;

      fl &= adj[prv][perm[i]];
    }

    if( fl )
      ++ans;
  } while( std::next_permutation(all(perm)) );

  printf( "%d\n", ans );
  
  return 0;
}