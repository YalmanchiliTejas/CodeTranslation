#include <iostream>
#include <cstdio>
#include <algorithm>
#include <array>
#include <vector>

using namespace std;

int main() {
  while ( true ) {
	int n, m;
	cin >> n >> m;
	if ( n == 0 && m == 0 ) break;

	vector<int> vs( n + m );
	for ( int i = 0; i < n + m; i++ ) {
	  int val;
	  cin >> val;
	  vs[ i ] = val;
	}
	sort( vs.begin(), vs.end() );
	int max_range = 0;
	int before = 0;
	for ( const int val : vs ) {
	  max_range = max( max_range, val - before );
	  before = val;
	}
	cout << max_range << endl;
  }  
}