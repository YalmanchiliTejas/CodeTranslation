#include <iostream>
#include <vector>
#define int long long
using namespace std;
const int ma = 3001;
const int inf = 1e15;
template< typename T >inline istream & operator>>( istream & I,vector< T > & v)
{for( int i = 0; i < v.size(); i++ ) I >> v[i]; return I;}
int dp[ma][ma];
int used[ma][ma];
vector< int > a;
int dfs( int l, int r )
{
    if( l == r ) return 0;
    if( used[l][r] ) return dp[l][r];
    used[l][r] = 1;
    int res = -inf;
    res = max( res, a[l] - dfs(l + 1, r) );
    res = max( res, a[r - 1] - dfs( l, r - 1 ) );
    return dp[l][r] = res;
}
main()
{
    int n;cin >> n;
    a = vector< int > (n);
    cin >> a;
    cout << dfs( 0, n ) << endl;
    return 0;
}