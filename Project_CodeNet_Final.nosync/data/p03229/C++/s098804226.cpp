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
static const int SIZE = 500005;

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
    cin >> n;
    int a[SIZE];
    for( int i = 0; i < n; ++i ) {
        cin >> a[i];

    }
    sort( a, a + n );
    int mi = n / 2;
    vector< int > v, w;
    v.pb( a[n / 2] );
    w.pb( a[n / 2] );
    int l = 0, r = n - 1;
    while( l < mi || r > mi ) {
        if( l == mi || r == mi ) {
            if( l == mi ) {
                v.pb( a[r] );
                --r;

            } else {
                v.pb( a[l] );
                ++l;

            }
        } else {
            v.pb( a[l] );
            v.pb( a[r] );
            ++l; --r;

        }
    }

    l = 0; r = n - 1;
    while( l < mi || r > mi ) {
        if( l == mi || r == mi ) {
            if( l == mi ) {
                w.pb( a[r] );
                --r;

            } else {
                w.pb( a[l] );
                ++l;

            }
        } else {
            w.pb( a[r] );
            w.pb( a[l] );
            ++l; --r;

        }
    }

    LL resv = 0, resw = 0;
    for( int i = 1; i < n; ++i ) {
        resv += abs( v[i] - v[i - 1] );
        resw += abs( w[i] - w[i - 1] );

    }

    cout << max( resv, resw ) << endl;
    return 0;
}

