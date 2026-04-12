#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t h, w;
    cin >> h >> w;
    vector<string> v( h );
    for ( size_t i = 0; i < h; ++i ) {
        cin >> v.at( i );
    }
    for ( size_t i = 0, j; i < h; ++i ) {
        for ( j = 0; j < w; ++j ) {
            if ( v.at( i ).at( j ) == '#' )
                break;
        }
        if ( j == w ) {
            for ( size_t j = 0; j < w; ++j ) {
                v.at( i ).at( j ) = '@';
            }
        }
    }
    for ( size_t i = 0,j; i < w; ++i ) {
        for ( j = 0; j < h; ++j ) {
            if ( v.at( j ).at( i ) == '#')
                break;
        }
        if ( j == h ) {
            for ( size_t j = 0; j < h; ++j ) {
                v.at( j ).at( i ) = '@';
            }
        }
    }
    bool f;
    for ( size_t i = 0; i < h; ++i ) {
        f = false;
        for ( size_t j = 0; j < w; ++j ) {
            if ( v.at( i ).at( j ) != '@' ) {
                cout << v.at( i ).at( j );
                f = true;
            }
        }
        if ( f == true )
            cout << "\n"s;
    }
}