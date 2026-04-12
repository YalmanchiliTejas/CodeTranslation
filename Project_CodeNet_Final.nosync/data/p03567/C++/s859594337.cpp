#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    string str;
    cin >> str;

    bool flag = false;
    for( int i = 0; str[ i ] != '\0'; i++ ){
        if( str[ i ] == 'A' && str[ i + 1 ] == 'C' ){
            flag = true;
        }
    }

    cout << ( flag == true ? "Yes" : "No" ) << endl;

    return EXIT_SUCCESS;
}