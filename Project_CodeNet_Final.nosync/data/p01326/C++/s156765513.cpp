
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;

typedef istringstream ISS;
typedef ostringstream OSS;
typedef vector<string> VS;
typedef int INT;
typedef vector<INT> VI;
typedef vector<VI> VVI;
typedef pair <INT, INT> II;
typedef vector <II> VII;

template<class T> ostream& operator << ( ostream& os, vector<T> v ) {
    for ( typename vector<T>::iterator it_i = v.begin(); it_i != v.end(); ++it_i ) {
        os << *it_i << ", ";
    }
    return os;
}


typedef long long LL;

const int MOD = 1000000;
const int SIZE = 1001;

const string utf8[4][4] = {
    { "0xxxxxxx" },
    { "110yyyyx", "10xxxxxx" },
    { "1110yyyy", "10yxxxxx", "10xxxxxx" },
    { "11110yyy", "10yyxxxx", "10xxxxxx", "10xxxxxx" }
};
int n;
LL dp[SIZE];

LL calc( VS& L, int k, int len ) {
    LL res = 1;
    int y1 = 0, yx = 0;
    for ( int i = 0; i < len; ++ i ) {
        const string& s = L[k+i];
        const string& u = utf8[len-1][i];
        LL ret = ([&]( const string& s, const string& u ) -> LL {
                LL res = 1;
                auto isNumber = []( const char c ) -> bool { return c == '0' || c == '1'; };
                for ( int i = 0; i < 8; ++ i ) {
                    if ( isNumber( u[i] ) ) {
                        if ( s[i] != 'x' && s[i] != u[i] ) return 0;
                    
                    } else if ( u[i] == 'x' ) {
                        if ( s[i] == 'x' ) {
                            res *= 2;
                        }
                    } else if ( u[i] == 'y' ) {
                        if ( s[i] == 'x' ) {
                            yx ++;
                        } else if ( s[i] == '1' ) {
                            y1 ++;
                        }
                    }
                }
                return res;
            })( s, u );
        if ( ret == 0 ) return 0;
        res *= ret;
        res %= MOD;
    }

    if ( len == 1 ) {
        return res;
    }
    if ( y1 == 0 && yx == 0 ) return 0;
    if ( y1 > 0 ) {
        res *= 1 << yx;
    } else {
        res *= ( 1 << yx ) - 1;
    }
    res %= MOD;
    
    return res;
}

LL solve( VS L ) {
    bool flag = true;
    fill( dp, dp + SIZE, 0 );
    dp[0] = 1;
    for ( int i = 1; i <= n; ++ i ) {
        for ( int j = 1; j <= 4; ++ j ) {
            if ( i - ( j - 1 ) - 1 < 0 ) continue;
            LL ret = calc( L, i - ( j - 1 ) - 1, j );
            if ( ret == 0 ) continue;
            flag = false;
            dp[i] += ( dp[i-j] * ret ) % MOD;
            dp[i] %= MOD;
        }
    }
    
    return flag ? 0 : dp[n];
}

int main() {
    while ( cin >> n && n ) {
        VS lines(n);
        for ( int i = 0; i < n; ++ i ) cin >> lines[i];
        cout << solve( lines ) << endl;
    }
    return 0;
}