#include<iostream>
using namespace std;

int main()
{
    int p[100], s[100];

    int x, y, i = 0;
    char period;
    while( cin >> x >> period >> y )
    {
        if( x == 0 && y == 0 )
            break;
        p[i] = x;
        s[i] = y;
        i++;
    }

    for( int j = 0; j < i - 1; j++ )
    {
        for( int k = j + 1; k < i; k++ )
        {
            if( s[j] < s[k] )
            {
                int temp = s[j];
                s[j] = s[k];
                s[k] = temp;

                temp = p[j];
                p[j] = p[k];
                p[k] = temp;
            }
        }
    }

    int change = -1, h = 0;
    for( int j = 0; j < i; j++ )
    {
        if( s[j] != change )
        {
            change = s[j];
            h++;
        }
        s[j] = h;
    }

    int q;
    while( cin >> q )
    {
        for( int j = 0; j < i; j++ )
        {
            if( p[j] == q )
                cout << s[j] << endl;
        }
    }
    
    return 0;
}
