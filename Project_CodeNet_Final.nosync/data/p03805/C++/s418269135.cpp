#include <iostream>
#include <vector>
using namespace std;

long long int n, m;
vector< vector< long long int > > v;
long long int ans;

void kansu( long long int k, bool f[10], long long int cnt ) {

  if ( cnt == n ) {
    ans++;
    return;
  }

  for ( long long int i = 0; i < v[k].size(); i++ ) {

    long long int p = v[k][i];
    if ( f[p] == false ) {
      f[p] = true;
      kansu( p, f, cnt + 1 );
      f[p] = false;
    }

  }

  return;
}

int main() {

  cin >> n >> m;

  for ( long long int i = 0; i < n; i++ ) {
    vector < long long int > vv;
    v.push_back( vv );
  }

  for ( long long int i = 0; i < m; i++ ) {

    long long int a, b;
    cin >> a >> b;
    a--;
    b--;
    v[a].push_back( b );
    v[b].push_back( a );

  }

  ans = 0;
  bool f[10] = {};
  f[0] = true;
  kansu( 0, f, 1 );

  cout << ans << endl;

  return 0;

}
