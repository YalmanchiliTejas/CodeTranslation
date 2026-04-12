#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {

  long long int n;
  cin >> n;

  long long int ans = 0;
  vector< long long int > v;

  for ( long long int i = 0; i < n; i++ ) {
    long long int in;
    cin >> in;
    v.push_back( in );
  }

  sort( v.begin(), v.end() );

  if ( v[n-1] > n * ( n - 2 ) + n - 2 ) {

    ans += n - 2;
    v[n-1] -= n * ( n - 2 );
    for ( long long int j = 0; j < n - 1; j++ ) {
      v[j] += n-2;
    }

    for ( long long int i = 0; i < n; i++ ) {
      if ( v[i] > ( n + 1 ) * 2 ) {
	long long int cnt = ( v[i] - ( n + 1 ) * 2 ) / ( n + 1 ) + 1;
	ans += cnt * ( n + 1 );
	v[i] -= cnt * ( n + 1 );
      }
    }

  }

  while( true ) {

    bool f = true;
    for ( long long int i = 0; i < n; i++ ) {
      if ( v[i] >= n ) {
	f = false;
	long long int cnt = v[i] / n;
	ans += cnt;
	v[i] %= n;
	for ( long long int j = 0; j < n; j++ ) {
	  if ( j == i ) continue;
	  v[j] += cnt;
	}
	break;
      }
    }
    if ( f == true ) break;

  }

  cout << ans << endl;

  return 0;

}
