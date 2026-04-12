#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;

  bool isConnected[ N + 1 ][ N + 1 ];
  for( int i = 0; i < ( N + 1 ); ++i )
  {
    for( int j = 0; j < ( N + 1 ); ++j )
    {
      isConnected[ i ][ j ] = false;
    }
  }

  int a, b;
  for( int i = 0; i < M; ++i )
  {
    cin >> a >> b;
    isConnected[ a ][ b ] = true;
    isConnected[ b ][ a ] = true;
  }

  int order[ N - 1 ];
  for( int i = 0; i < ( N - 1 ); ++i )
  {
    order[ i ] = i + 2;
  }

  int ans = 0;

  do
  {
    int prev = 1;
    for( int i = 0; i < ( N - 1 ); ++i )
    {
      int curr = order[ i ];
      if( isConnected[ prev ][ curr ] )
      {
        if( i == ( N - 2 ) )
        {
          ++ans;
          break;
        }
        prev = curr;
      }
      else
      {
        break;
      }
    }
  }
  while( next_permutation( order, order + ( N - 1 ) ) );

  cout << ans << endl;

  return 0;
}
