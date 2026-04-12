#include <iostream>


using namespace std;


bool** VV;
int num_vertex;
int num_edge;
bool* is_visited;


bool is_reached_all_nodes( int size ) {
    for ( int i = 0; i < size; i++ ) {
        if ( !is_visited[ i ] ) { return false; }
    }
    return true;
}


int trace( int previous, int current ) {
    if ( is_visited[ current ] ) { return 0; }

    is_visited[ current ] = true;
    if ( is_reached_all_nodes( num_vertex ) ) {
        is_visited[ current ] = false;
        return 1;
    }
    
    int result = 0;
    for ( int next = 0; next < num_vertex; next++ ) {
        if ( previous == next ) { continue; }
        
        if ( VV[ current ][ next ] ) {
            result += trace( current, next );
        }
    }

    is_visited[ current ] = false;
    return result;
}


int main() {
    cin >> num_vertex >> num_edge;

    is_visited = new bool[ num_vertex ];
    
    VV = new bool*[ num_vertex ];
    for ( int i = 0; i < num_vertex; i++ ) {
        VV[ i ] = new bool[ num_vertex ];
    }

    for ( int i = 0; i < num_edge; i++ ) {
        int a, b;
        cin >> a >> b;
        VV[ a - 1 ][ b - 1 ] = true;
        VV[ b - 1 ][ a - 1 ] = true;
    }

    cout << trace( -1, 0 ) << endl;
    
    delete[] is_visited;

    for ( int i = 0; i < num_vertex; i++ ) {
        delete[] VV[ i ];
    }
    delete[] VV;
    
    return 0;
}
