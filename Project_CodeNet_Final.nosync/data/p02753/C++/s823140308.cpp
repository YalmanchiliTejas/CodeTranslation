#include <bits/stdc++.h>
#define mem( a , b ) memset( a , b , sizeof( a ) )
using namespace std;
int _I(){ int x; scanf("%d",&x); return x; }
long long _IL(){ long long x; scanf("%lld",&x); return x; }


struct node
{
        int v , w;
        node(){};
        node( int x , int y )
        {
                v = x;
                w = y;
        }

        bool operator < ( const node &R ) const
        {
                if( w == R.w ) return v < R.v;
                return w > R.w;
        }
};

long long mod;
long long bigmod( long long b , long long p )
{
        if( p == 0 ) return 1LL;
        long long r = bigmod( 2 , p/2 );
        r = ( ( r % mod ) * ( r % mod ) ) % mod;
        if( p & 1 )
        {
                r = ( ( b % mod ) * ( r % mod ) ) % mod;
        }
        return r;
}
vector< int > s1 , s2;
vector< pair< int , int > > divisor;
map< int , int > mp;
void solve()
{
       set< char > _st;
       string s;
       cin>>s;
       if( s[ 0 ] == s[ 1 ] && s[ 1 ] == s[ 2 ] )
       {
               cout<<"No\n";
       }
       else cout<<"Yes\n";
}
int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
       // int t = _I();
        //while( t-- )
                solve();

        return 0;
}
