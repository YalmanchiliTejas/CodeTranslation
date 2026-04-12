#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> PII;
typedef pair <int, PII> PIP;

int main( void )
{
  int N;
  while ( cin >> N && N ) {
    vector <PIP> L(N);
    for ( int i = 0; i < N; i++ ) {
      int y, m, d;
      cin >> y >> m >> d;
      PIP e( y, PII( m, d ) );
      L[i] = e;
    }
    sort( L.begin(), L.end() );
    for ( vector <PIP> ::iterator it = L.begin(); it != L.end(); it++ ) {
      PIP e = *it;
      int y, m, d;
      y = e.first;
      m = e.second.first;
      d = e.second.second;
      cout << setw(4) << setfill('0') << y << " " << setw(2) << setfill('0')  << m << " " << setw(2) << setfill('0')  << d << endl;
    }
  }
  return 0;
}