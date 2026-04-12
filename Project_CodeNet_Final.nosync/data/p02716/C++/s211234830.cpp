#include <iostream>
using namespace std;

#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

int main() {

    long long int n;
    cin >> n;

    vector< long long int > v;
    for ( long long int i = 0; i < n; i++ ) {
        long long int in;
        cin >> in;
        v.push_back( in );
    }

    long long int d[3][214514] = {};
    d[0][0] = v[0];
    d[1][1] = v[1];

    for ( long long int i = 1; i < n; i++ ) {
        if ( i >= 2 ) {
            d[0][i] = d[0][i-2] + v[i];
            d[1][i] = d[1][i-2] + v[i];
            d[2][i] = d[2][i-2] + v[i];
        }
        if ( i >= 3 ) {
            d[1][i] = max( d[0][i-3] + v[i], d[1][i] );
            d[2][i] = max( d[1][i-3] + v[i], d[2][i] );
        }
        if ( i >= 4 ) {
            d[2][i] = max( d[0][i-4] + v[i], d[2][i] );
        }
    }

    long long int ans = 0;
    if ( ( n % 2 ) == 0 ) {
        ans = max( d[0][n-2], d[1][n-1] );
    } else {
        ans = max( d[0][n-3], d[1][n-2] );
        ans = max( ans      , d[2][n-1] );
    }
    cout << ans << endl;

    return 0;

}
