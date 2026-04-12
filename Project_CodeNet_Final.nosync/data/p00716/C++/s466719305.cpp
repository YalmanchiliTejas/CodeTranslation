#include<iostream>
using namespace std;

int main()
{
    int m, money, y, n, c;
    bool q;
    double p;

    cin >> m;

    for( int i = 0; i < m; i++ )
    {
        cin >> money >> y >> n;

        int sum = 0;
        for( int j = 0; j < n; j++ )
        {
            cin >> q >> p >> c;
            
            int a = money;
            
            if( q )
            {
                for( int k = 0; k < y; k++ )
                {
                    int b = (int)( a * p );
                    a += b - c;
                }
                if( sum < a )
                    sum = a;
            }
            if( !q )
            {
                int d = 0;
                for( int k = 0; k < y; k++ )
                {
                    int b = (int)( a * p );
                    d += b;
                    a -= c;
                }
                if( sum < d + a )
                    sum = d + a;
            }
            
            if( sum < a )
                sum = a;
        }
        cout << sum << endl;
    }
    return 0;
}
