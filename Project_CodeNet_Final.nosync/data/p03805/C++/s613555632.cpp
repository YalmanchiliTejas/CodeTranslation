#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>


typedef long double ld;
typedef long long ll;
using namespace std;
const ll MX=5e5+9;
const int MAXN = 10100;
const ld pi = acos(-1);
const ll mod = 1e9+7;

//bool cmp ( int a,int b ) { return a>b; }
ll vl;
ll po ( ll a , ll b )
{
    if ( b==0 ) { return 1; }
    ll x = po ( a , b/2 );
    x *= x;
    if ( b%2 ) { x*=a; }
    return x;
}
int power(int p)
{
    if(p==0)return 1;
    if(p==1)return vl;
    if(p%2)return (vl*power(p-1))%mod;
    long long x=power(p/2);
    return (x*x)%mod;
}
int mod_inv(ll a,ll b)
{
    vl=b;
    return (a*power(mod-2))%mod;
}
ll gcd (  ll a , ll b )
{
    if ( b==0 ) return a;
    else { return gcd( b , a%b ); }
}

bool cmp ( int a ,int b ) { return (a>b); }
int dx[]={ 0 , 0 , -1 , 1 };
int dy[]={ 1 , -1 , 0 , 0 };

vector <int> v[MX];
bool vis[MX];
ll ans=0;
int n,m;
set<int> edge[MX];
void dfs( int x , int mask )
{
    if ( __builtin_popcount(mask)==n ) { ans++; return; }
    for ( int i=0 ; i<n ; i++ )
    {
        if ( !((1<<i)&mask) && edge[x].count(i+1) ) { dfs( i+1 , mask|(1<<i) ); }
    }

}

int main()
{

    cin>>n>>m;
    for ( int i=0 ; i<m ; i++ )
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back( b );
        v[b].push_back( a );
        edge[a].insert( b );
        edge[b].insert( a );
    }
    dfs( 1 , 1 );
    cout<<ans;

    return 0;
}
