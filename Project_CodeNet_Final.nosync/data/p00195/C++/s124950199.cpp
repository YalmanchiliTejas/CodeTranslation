#include<iostream>
using namespace std;

int main()
{
    int a[5], b[5];
    char c[5] = {'A','B','C','D','E'};


    while( cin >> a[0] >> b[0] )
    {
        if( a[0] + b[0] == 0 )
            break;
        int max = a[0] + b[0], j = 0;
        for( int i = 1; i < 5; i++ )
        {
            cin >> a[i] >> b[i];
            if( max < a[i] + b[i] )
            {
                max = a[i] + b[i];
                j = i;
            }
        }
        cout << c[j] << " " << max << endl;
    }

    return 0;
}
