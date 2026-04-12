#include<iostream>
using namespace std;

//WA
typedef unsigned long long int ll;

int main()
{
    ll a, b, c, sum = 0;
    const ll con = 1000000007;

    cin >> a >> b >> c;

    if( a > c )
    {
        cout << c % con << endl;
        return 0;
    }

    sum += c % con;
    if( ( c - a + 1 ) % ( a - b ) == 0 )
        sum += ( ( c - a + 1 ) / ( a - b ) % con ) * ( b % con );
    else
        sum += ( ( ( c - a + 1 ) / ( a - b ) + 1 ) % con ) * ( b % con );

    cout << sum % con << endl;

    return 0;
}
