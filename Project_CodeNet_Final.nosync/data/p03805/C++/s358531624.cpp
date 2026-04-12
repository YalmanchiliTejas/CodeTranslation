#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
using namespace std;
typedef long long ll;
typedef double d;
typedef int i;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n , m , a , b , g[9][9] = {} , z = 0;
    cin >> n >> m;
    for ( int i = 0 ; i < m ; i++ ) cin >> a >> b , g[a][b] = g[b][a] = 1;
    int c[8] = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8};
    do {
        bool y = 1;
        for ( int i = 1 ; i < n ; i++ ) {
            if ( g[c[i - 1]][c[i]] == 0 ) y = 0;
        }
        if ( y ) z++;
    } while ( next_permutation( c + 1 , c + n ) );
    cout << z;
}