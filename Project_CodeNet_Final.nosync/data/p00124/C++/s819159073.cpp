#include <cstdio>
#include <utility>
#include <string>
#include <iostream>

using namespace std;

struct team{
    string s;
    int input, point;
};

int main()
{
    bool first = 1;
    while( 1 )
    {
        int n;
        scanf( "%d", &n );
        if( n == 0 ) break;
        if( !first )
        {
            printf( "\n" );
        }
        else
        {
            first = 0;
        }
        team p[10];
        int i = 0;
        while( i < n )
        {
            string s;
            cin >> s;
            int w,l,d;
            cin >> w >> l >> d;
            p[i].s = s;
            p[i].point = 3 * w + d;
            p[i].input = i;
            i++;
        }
        for( int j = 0; j < n; j++ )
        {
            for( int k = j; k < n; k++ )
            {
                if( p[j].point < p[k].point )
                {
                    swap( p[j], p[k] );
                }
            }
        }
        for( int j = 0; j < n; j++ )
        {
            for( int k = j; k < n; k++ )
            {
                if( p[j].point == p[k].point && p[j].input > p[k].input )
                {
                    swap( p[j], p[k] );
                }
            }
        }
        for( int j = 0; j < n; j++ )
        {
            cout << p[j].s << ',' << p[j].point << '\n';
        }
    }   
    return 0; 
}
