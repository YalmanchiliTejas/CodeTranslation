#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t h, w;
    cin >> h >> w;
    vector<string> v( h );
    for ( size_t i = 0; i < h; ++i ) {
        cin >> v.at( i );
    }
    for ( size_t i = 0, c; i < h; ++i ) {
        c = 0;
        for ( size_t j = 0; j < w; ++j ) {
            if ( v.at( i ).at( j ) == '.' || v.at( i ).at( j ) == '@' )
                ++c;
        }
        if ( c == w ) {
            for ( size_t j = 0; j < w; ++j ) {
                v.at( i ).at( j ) = '@';
            }
        }
    }
    for ( size_t i = 0, c; i < w; ++i ) {
        c = 0;
        for ( size_t j = 0; j < h; ++j ) {
            if ( v.at( j ).at( i ) == '.' || v.at( j ).at( i ) == '@' )
                ++c;
        }
        if ( c == h ) {
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