#include <iostream>
using namespace std;
typedef long long ll;
int main( void )
{
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  ll a[55];
  for( int i=0; i<N; i++ ){
    cin >> a[i];
  }
  ll ret = 0;
  while( 1 ){
    ll d = 0;
    for( int i=0; i<N; i++ ){
      d += a[i] / N;
      a[i] = (a[i] % N) - (a[i]/N);
    }
    int f = 1;
    for( int i=0; i<N; i++ ){
      a[i] += d;
      if( a[i] >= N ) f = 0;
    }
    ret += d;
    if( f ) break;
  }
  cout << ret << endl;
}