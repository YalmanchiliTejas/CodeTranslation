#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <forward_list>
#include <random>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <unordered_map>
#include <unordered_set>
#endif

#define F first
#define S second
#define MP make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define lcm( a, b ) (a)/__gcd((a),(b))*(b)
#define endl '\n'

using namespace std;

typedef long long LL;
typedef pair< int, int > P;
typedef pair< LL, LL > LP;
typedef pair< int, P > iP;
typedef pair< P, P > PP;

static const int INF = INT_MAX;
static const LL LINF = LLONG_MAX;
static const int MIN = INT_MIN;
static const LL LMIN = LLONG_MIN;
static const int MOD = 1000000007;
static const int SIZE = 100005;

const int dx[] = {0, -1, 1, 0};
const int dy[] = {-1, 0, 0, 1};

vector< int > Div( int n ) {
    vector< int > ret;
    for( int i = 1; i * i <= n; ++i ) {
        if( n % i == 0 ) {
            ret.pb( i );

            if( i * i != n ) ret.pb( n / i );
        }
    }
    sort( all( ret ) );
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    for( int i = 0; i < 4; ++i ) {
        int res[SIZE];
        if( i == 0 ) {
            res[0] = 0;
            res[1] = 0;

        } else if( i == 1 ) {
            res[0] = 0;
            res[1] = 1;

        } else if( i == 2 ) {
            res[0] = 1;
            res[1] = 0;

        } else {
            res[0] = 1;
            res[1] = 1;

        }
        
        /* 0 : 羊   1 : 狼 */
        for( int j = 1; j < s.size() - 1; ++j ) {
            if( s[j] == 'o' ) {
                if( res[j] == 0 ) {
                    res[j + 1] = res[j - 1];

                } else {
                    if( res[j - 1] == 0 ) res[j + 1] = 1;
                    else res[j + 1] = 0;

                }

            } else {
                if( res[j] == 0 ) {
                    if( res[j - 1] == 0 ) res[j + 1] = 1;
                    else res[j + 1] = 0;

                } else {
                    res[j + 1] = res[j - 1];

                }
            }
        }

        if( res[n - 1] == 0 ) {
            if( s[n - 1] == 'o' ) {
                if( res[n - 2] != res[0] ) continue;

            } else {
                if( res[n - 2] == res[0] ) continue;

            }

        } else {
            if( s[n - 1] == 'o' ) {
                if( res[n - 2] == res[0] ) continue;

            } else {
                if( res[n - 2] != res[0] ) continue;

            }
        }

        if( res[0] == 0 ) {
            if( s[0] == 'o' ) {
                if( res[n - 1] != res[1] ) continue;

            } else {
                if( res[n - 1] == res[1] ) continue;

            }

        } else {
            if( s[0] == 'o' ) {
                if( res[n - 1] == res[1] ) continue;

            } else {
                if( res[n - 1] != res[1] ) continue;

            }
        }

        for( int j = 0; j < n; ++j ) {
            if( res[j] == 0 ) {
                cout << 'S';

            } else {
                cout << 'W';

            }
        }
        cout << endl;
        return 0;

    }
    cout << -1 << endl;
    return 0;
}

