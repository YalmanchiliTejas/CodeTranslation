#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <map>
using namespace std;
struct result {
  int id;
  int score;
  int rank;
};

bool operator<( const result &r1, const result &r2 ) {
  return r1.score < r2.score;
}

int main() {
  vector<result> results;
  map<int, int> idx_rel;
  while( 1 ) {
    string line;
    cin >> line;
    replace( line.begin(), line.end(), ',', ' ' );

    istringstream iss( line );
    result r;
    iss >> r.id >> r.score;
    if( !r.id && !r.score ) { break; }
    results.push_back( r );
  }
  sort( results.begin(), results.end() );
  int len = results.size();
  int rank = 1;
  for( int i = len - 1; i >= 0; i-- ) {
    if( i < len - 1 && results[ i ] < results[ i + 1 ] ) {
      rank++;
    }
    results[ i ].rank = rank;
    idx_rel[ results[ i ].id ] = i;
  }
  
  int t;
  while( cin >> t ) {
    cout << results[ idx_rel[ t ] ].rank << endl;
  }
  return EXIT_SUCCESS;
}