#include <bits/stdc++.h>
using namespace std;

#define FOR( i, m, n )   for( int i = m; i < n; i++ )
#define REP( i, n )      FOR( i, 0, n )
#define ALL( a )         (a).begin(), (a).end()

int result( vector<int>& d );

int main(){
  int n; cin >> n;

  vector<int> d( n ), cd;
  REP( i, n ){
    cin >> d[i];
    d[i] /= 10;
  }
  
  reverse_copy( ALL(d), back_inserter(cd) );

  if( result( d ) && result( cd ) ){
    cout << "yes" << endl;
  }else{
    cout << "no" << endl;
  }
}

int result( vector<int>& d ){
  int dmax = 0;

  REP( i, d.size() ){
    if( dmax < i ) return 0;
    dmax = max( dmax, i + d[i] );
  }
  return 1;
}

