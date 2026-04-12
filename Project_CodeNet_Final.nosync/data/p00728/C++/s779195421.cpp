#include<iostream>
using namespace std;

int main()
{
    int n, a[100];

    while( cin >> n )
    {
        if( n == 0 )
            break;
        for( int i = 0; i < n; i++ )
            cin >> a[i];

        int min = 10000000, max = -1, sum = 0;
        for( int i = 0; i < n; i++ )
        {
            if( min > a[i] )
                min = a[i];
            if( max < a[i] )
                max = a[i];
            sum += a[i];
        }
        cout << ( sum - min - max ) / ( n - 2 ) << endl;
    }
    return 0;
}

