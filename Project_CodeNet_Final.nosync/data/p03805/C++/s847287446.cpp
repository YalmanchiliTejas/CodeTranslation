#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
#define FOR(i,a,b)   for(ll i = (a); i < (b); i++ )
#define REP(i, n)    FOR(i,0,n)
typedef pair< ll, ll >   cp2;
typedef pair< string, cp2 >   cp3;
#define fi first
#define se second
#define sec  se.fi
#define thr  se.se
const ll mod = 1000000007;
//              123456789


///////////////////////////////////////////////
//
//
///////////////////////////////////////////////

////////////////////////////////////////////////
////////////////////////////////////////////////

int N, M;
int a,b;
bool p[10][10];
bool f[10];
int ans = 0;

void dfs( int v ){
    f[v] = true;
    bool flag = true;
    REP( i, N ) if( !f[i] ) flag = false;
    if( flag ){
        ans++;
        f[v] = false;
        return;
    }
    FOR( i, 1, N ){
        if( f[i] ) continue;
        if( p[v][i] ){
            dfs( i );
        }
    }
    f[v] = false;
    return;
}


int main(){
    
    fill( &p[0][0], &p[10][0], false );
    fill( f, f+10, false );
    
    cin>>N>>M;
    REP(i,M){
        cin>>a>>b;
        a--;
        b--;
        p[a][b] = true;
        p[b][a] = true;
    }
    
    dfs( 0 );
    
    cout<<ans<<endl;
    
    return 0;
}
