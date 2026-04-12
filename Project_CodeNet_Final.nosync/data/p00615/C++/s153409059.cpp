#include<iostream>
using namespace std;

int main()
{
    int n, m;

    while( cin >> n >> m )
    {
        if( n + m == 0 )
            break;
        
        int* a = new int[n];
        int* b = new int[m];
        int* c = new int[n+m];

        for( int i = 0; i < n; i++ )
            cin >> a[i];

        for( int i = 0; i < m; i++ )
            cin >> b[i];

        int i = 0, j = 0;
        while( i < n && j < m )
        {
            if( a[i] < b[j] )
            {
                c[i+j] = a[i];
                i++;
            }
            else
            {
                c[i+j] = b[j];
                j++;
            }
        }
        while( i < n )
        {
            c[i+j] = a[i];
            i++;
        }
        while( j < m )
        {
            c[i+j] = b[j];
            j++;
        }

        int ma = c[0];
        for( i = 0; i < n + m - 1; i++ )
            ma = ma > c[i+1] - c[i] ? ma : c[i+1] - c[i];

        cout << ma << endl;

        delete a, b, c;
    }

    return 0;
}
