#include <iostream>
#include <string>
using namespace std;

int main( void ) {
    ios::sync_with_stdio( false );
    int n, m;
    string s;
    cin >> n >> s >> m;
    char ch = s[ m - 1 ];
    for( int i = 0; i < s.length(); ++i ) if( s[ i ] != ch ) s[ i ] = '*';
    cout << s << '\n';
    return 0;
}
