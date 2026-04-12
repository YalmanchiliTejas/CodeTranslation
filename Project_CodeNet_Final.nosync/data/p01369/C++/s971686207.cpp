#include <iostream>
using namespace std;

bool check( char c )
{
    char C[5+4+2+1] = "yuiophjklnm";
    for ( int i = 0; i < 5+4+2+1; i++ ) {
        if ( c == C[i] ) return true;
    }
    return false;
}

int main( void )
{
    string input;
    while ( cin >> input && input != "#" ) {
        int answer = 0;
        bool flag = check( input[0] );
        for ( string ::iterator it = input.begin(); it != input.end(); it++ ) {
            if ( flag != check( *it ) ) {
                answer++;
            }
            flag = check( *it );
        }
        cout << answer << endl;
    }
    return 0;
}