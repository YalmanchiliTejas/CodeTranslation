//  Copyright © 2020 Diego Garcia Rodriguez del Caviso. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define pii pair < ll , ll > 
#define fi first
#define se second
#define INF 1e18
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
#define forn(i,a,b) for (ll i = a; i <= b; i ++ )
#define mod(n,k) (((n%k)+k)%k)
using namespace std;
typedef long long ll;

ll N, a[MAX];
map < pii , ll > vis;

ll dfs( ll p , ll l ) {
    if( ! l )
        return 0;
    if( p > N )
        return -INF;
    if( p + l * 2 - 2 > N )
        return -INF;
    auto it = vis.find( { p , l} );
    if( it != vis.end() )
        return it->second;
    
    ll ans = -INF;
    ans = max( ans , dfs( p + 2 , l - 1 ) + a[p] );
    ans = max( ans , dfs( p + 3 , l - 1 ) + a[p] );
    ans = max( ans , dfs( p + 4 , l - 1 ) + a[p] );
    return vis[{p , l}] = ans;
    
}

int main()
{
    optimiza_io
    cin >> N;
    forn( i , 1 , N )
        cin >> a[i];
    
    cout << max( dfs( 1 , N/2 ) , max( dfs( 2 , N/2 ) , dfs( 3 , N/2 ) ) ) << "\n";
    return 0;
}

// CHECAR LIMITES 