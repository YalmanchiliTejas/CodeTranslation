#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;

typedef vector <int> VI;

int main() {
    int n, m;
    while ( cin >> n >> m ) {
        if ( n == 0 && m == 0 ) break;
        VI D(n+m);
        for ( int i = 0; i < n; ++ i ) {
            cin >> D[i];
        }
        for ( int i = 0; i < m; ++ i ) {
            cin >> D[n+i];
        }
        sort( D.begin(), D.end() );
        int res = 0;
        int c = 0;
        for ( int i = 0; i < n + m; ++ i ) {
            res = max( res, abs( c - D[i] ) );
            c = D[i];
        }
        cout << res << endl;
    }
	return 0;
}