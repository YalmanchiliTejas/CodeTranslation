#include<iostream>
using namespace std;

bool judgeLeapYear( int* a, int x, int n )
{
    for( int i = 0; i < n; i++ )
        if( x % a[i] == 0 )
        {
            if( ( i + 1 ) % 2 != 0 )
                return true;
            else
                return false;
        }
    if( n % 2 == 0 )
        return true;
    else
        return false;
}

int main()
{
    int a[50], n, x, y;

    while( cin >> n >> x >> y )
    {
        if( n + x + y == 0 )
            break;

        for( int i = 0; i < n; i++ )
            cin >> a[i];

        int cnt = 0;
        for( int i = x; i <= y; i++ )
            if( judgeLeapYear( a, i, n ) )
                cnt++;

        cout << cnt << endl;

    }
    return 0;
}
