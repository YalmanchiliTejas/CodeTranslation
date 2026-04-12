#include <iostream>
using namespace std;

int n_path = 0;
bool done[9] = { false };
bool path[9][9];

void recursion( int pos, int n ) {
    
    bool is_all_done = true;
    
    done[pos] = true;
    
    for ( int i = 1; i <= n; i++ ) {
        if ( !done[i] ) { is_all_done = false; }
    }
    
    if ( is_all_done ) {
        n_path++;
        done[pos] = false;
        return;
    }
    
    for ( int i = 1; i <= n; i++ ) {
        if ( path[pos][i] && !done[i] ) {
            recursion( i, n );
        }
    }
    
    done[pos] = false;
    return;
}


int main() {
    
    int N, M;
    
    cin >> N;
    cin >> M;
    
    for ( int i = 1; i <= N; i++ ) {
    for ( int j = 1; j <= N; j++ ) {
        path[i][j] = false;
    }
    }
    
    for ( int i = 0; i < M; i++ ) {
        int a, b;
        cin >> a;
        cin >> b;
        
        path[a][b] = true;
        path[b][a] = true;
    }
    
    recursion( 1, N );
    
    cout << n_path << endl;
    
    return 0;
}