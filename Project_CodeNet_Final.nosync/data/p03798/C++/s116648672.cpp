#include <bits/stdc++.h>
using namespace std;

const int DIM = 1e5 + 5;

string str;
bool ans[DIM];

int main( void ) {
    
    int n;
    cin >> n >> str;
    
    for( char &ch : str )
        ch = ( ch == 'x' );
    
    bool ok = false;
    for( int v0 = 0; v0 <= 1 && ok == false; v0 ++ ) {
    for( int v1 = 0; v1 <= 1 && ok == false; v1 ++ ) {
        ans[0] = v0; ans[1] = v1;
        
        for( int i = 2; i < n; i ++ )
            ans[i] = ( ans[i - 2] ^ ans[i - 1] ^ str[i - 1] );
        
        if( ( ans[n - 2] ^ ans[n - 1] ^ str[n - 1] ) == ans[0] &&
            ( ans[1] ^ ans[0] ^ str[0] ) == ans[n - 1] ) ok = true;
    } }

    if( ok == false )
        cout << -1 << endl;
    else {
        for( int i = 0; i < n; i ++ )
            cout << ( ans[i] == 0 ? 'S' : 'W' );
        cout << endl;
    }
    
    return 0;
}