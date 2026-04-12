#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int r , c;
string s[ 105 ];
bool bad[ 105 ][ 105 ];

void go( int x , int y ) {
        bool f = true;
        for( int i = 0; i < c; i++ ) {
                if( s[x][i] == '#' ) {
                        f = false;
                        break;
                }
        }
        if( f ) {
              for( int i = 0; i < c; i++ ) {
                bad[x][i] = true;
            }
        }
        f = true;
        for( int i = 0; i < r; i++ ) {
                if( s[i][y] == '#' ) {
                        f = false;
                        break;
                }
        }
        if( f ) {
                for( int i = 0; i < r; i++ ) {
                    bad[i][y] = true;
            }
        }
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> r >> c;
        for( int i = 0; i < r; i++ ) cin >> s[i];
        for( int i = 0; i < r; i++ ) {
                for( int j = 0; j < c; j++ ) {
                        if( s[i][j] == '.' ) go( i , j );
                }
        }
        for( int i = 0; i < r; i++ ) {
                for( int j = 0; j < c; j++ ) {
                        if( !bad[i][j] ) cout << s[i][j];
                }
                cout << endl;
        }
        return 0;
}






