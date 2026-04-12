#include <bits/stdc++.h>
using namespace std;

const int DIM = 10;

bool oki[DIM];
vector<int> edg[DIM];

void back( int x, int cnt, int n, int &ans ) {
    oki[x] = true;
    
    if( cnt == n )
        ans ++;
    else {
        for( int y : edg[x] )
            if( oki[y] == false )
                back( y, cnt + 1, n, ans );
    }
        
    oki[x] = false;
    return;
}

int main( void ) {
    
    int n, m;
    cin >> n >> m;
    
    for( int i = 1; i <= m; i ++ ) {
        int a, b;
        cin >> a >> b;
        
        edg[a].push_back( b );
        edg[b].push_back( a );
    }
    
    int ans = 0;
    back( 1, 1, n, ans );
    
    cout << ans << endl;
    return 0;
}