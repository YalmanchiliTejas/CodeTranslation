#include <bits/stdc++.h>
using namespace std;
const int N = 350;
const int INF = 1<<30;

int a, b, s, t, sum, d[N][N], f[N][N];

inline void ck_min( int &a, int b ) { if( a > b ) a = b; }
inline void ck_max( int &a, int b ) { if( a < b ) a = b; }

inline bool check( int x, int y, int val )
{
    int res = INF;
    for( int i = 0; i <= 100; i ++ )
        for( int j = 0; j <= 100; j ++ )
            if( f[i][j] >= 0 ) ck_min( res, i*x + j*y + f[i][j] );

//  printf( "x:%d, y:%d, res:%d\n", x, y, res );
    return res == val;
}

int main()
{
    memset( f, -1, sizeof( f ) );

    scanf( "%d%d", &a, &b );
    for( int i = 1; i <= a; i ++ )
        for( int j = 1; j <= b; j ++ )
            scanf( "%d", &d[i][j] );

    s = 201, t = 202; 
    // s --> 1 --> 2 --> ... --> 100
    // t <-- 101 <-- 102 <-- ... <-- 200

    for( int i = 0; i <= 100; i ++ )
        for( int j = 0; j <= 100; j ++ )
        {
            int tmp = -INF;
            for( int _a = 1; _a <= a; _a ++ )
                for( int _b = 1; _b <= b; _b ++ )
                    ck_max( tmp, d[_a][_b] - i*_a - j*_b ); 
            f[i][j] = tmp; 
            if( f[i][j] < 0 ) break;

            sum ++;
//          printf( "i:%d, j:%d, f:%d\n", i, j, f[i][j] );
        }

    for( int i = 1; i <= a; i ++ )
        for( int j = 1; j <= b; j ++ )  
            if( !check( i, j, d[i][j] ) ) {
                printf( "Impossible\n" ); return 0;
            } 

    printf( "Possible\n" );

    printf( "%d %d\n", 202, sum+200 );
    for( int i = 1; i < 100; i ++ )
        printf( "%d %d X\n%d %d Y\n", i, i+1, i+101, i+100 );

    printf( "%d %d X\n%d %d Y\n", s, 1, 101, t );
    for( int i = 0; i <= 100; i ++ )
        for( int j = 0; j <= 100; j ++ )
            if( f[i][j] >= 0 )  printf( "%d %d %d\n", !i ? s : i, !j ? t : j+100, f[i][j] );

    printf( "%d %d\n", s, t );

    return 0;
}