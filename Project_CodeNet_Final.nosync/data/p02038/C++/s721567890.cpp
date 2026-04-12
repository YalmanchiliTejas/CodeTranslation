#include<iostream>
using namespace std;

char TF( char a, char b )
{
    if( a == 'T' && b == 'F' )
        return 'F';
    else
        return 'T';
}

int main()
{
    int n;

    cin >> n;

    char c[n];
    cin >> c[0] >> c[1];
    
    char res = TF( c[0], c[1] );
    for( int i = 2; i < n; i++ )
    {
        cin >> c[i];
        res = TF( res, c[i] );
    }

    cout << res << endl;

    return 0;
}
