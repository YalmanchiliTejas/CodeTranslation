#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

string s;
int d;
vector <int> V;
int len;
LL dp[ 2*N ][ 2 ][ 105 ];

LL go( int idx , int smaller , int sod  ) {
        if( idx >= len ) return sod%d == 0;
        if( dp[idx][smaller][sod] != -1 ) return dp[idx][smaller][sod];
        LL ret = 0;
        if( smaller ) {
                for( int i = 0; i <= 9; i++ ) {
                        ret += go( idx + 1 , 1 , (sod+i)%d );
                        ret %= MOD;
                }
        }
        else {
                for( int i = 0; i < V[idx]; i++ ) {
                        ret += go( idx + 1 , 1 , (sod+i)%d );
                        ret %= MOD;
                }
                ret += go( idx + 1 , 0 , (sod+V[idx])%d );
                ret %= MOD;
        }
        return dp[idx][smaller][sod] = ret%MOD;
}
LL solve( string s ) {
        V.clear();
        for( int i = 0; i < s.size(); i++ ) V.push_back( s[i]-'0' );
        len = V.size();
        memset( dp , -1 , sizeof( dp ) );
        return go( 0 , 0 , 0 );
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >> s >> d;
        cout << ( solve( s ) - 1 + MOD )%MOD << endl;
        return 0;
}











