#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10;
char m[MAXN][MAXN];
int h, w;
int dx[] = {0,1};
int dy[] = {1,0};
void dfs( int x, int y ){
    m[x][y] = 'V';
    for( int i = 0 ; i < 2 ; ++i ){
        if( x+dx[i] >= 0 && x+dx[i] < h && y+dy[i] >= 0 && y+dy[i] < w && m[x+dx[i]][y+dy[i]] == '#' ){
            dfs( x+dx[i], y+dy[i] );
            break;
        }
    }
}
int main(){

    cin >> h >> w;

    for( int i = 0 ; i < h ; ++i ){
        for( int j = 0 ; j < w ; ++j ){
            cin >> m[i][j];
        }
    }

    dfs(0,0);
    bool x = true;
    for( int i = 0 ; i < h ; ++i ){
        for( int j = 0 ; j < w ; ++j ){
            if( m[i][j] == '#' ) x = false;
        }
    }
    cout << ( x ? "Possible\n" : "Impossible\n" ) ;

}
