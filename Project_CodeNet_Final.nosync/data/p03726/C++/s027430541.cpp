#include <bits/stdc++.h>
using namespace std;

const int DIM = 1e5 + 5;

int deg[DIM];

vector<int> edg[DIM];
deque<int> que;

int dfs( int x, int f, bool &ok ) {
    int nr = 0;
    
    for( int y : edg[x] ) {
        if( y == f )
            continue;
        
        bool aux = dfs( y, x, ok );
        
        if( aux == true )
            deg[x] --;
    }
    
    if( deg[x] - (f != 0) >= 2 )
        ok = true;
    else
        return ( deg[x] - (f != 0) == 1 );
    
    return false;
}

int main( void ) {
    
    int n;
    cin >> n;
    
    for( int i = 2; i <= n; i ++ ) {
        int x, y;
        cin >> x >> y;
        
        edg[x].push_back( y );
        edg[y].push_back( x );
        deg[x] ++; deg[y] ++;
    }
    
    bool ok = false;
    bool aux = dfs( 1, 0, ok );
    
    if( ok == false )
        ok = !aux;
    
    cout << ( (ok == true) ? "First\n" : "Second\n" );
    return 0;
}
