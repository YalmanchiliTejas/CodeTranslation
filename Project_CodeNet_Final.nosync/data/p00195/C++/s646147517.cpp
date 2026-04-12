#include <cstdio>

using namespace std;

int max( int a, int b, int c, int d, int e )
{
    int pre1,pre2;
    if( a < b )
    {
        pre1 = b;
    }
    else
    {
        pre1 = a;
    }
    if( c < d )
    {
        pre2 = d;
    }
    else
    {
        pre2 = c;
    }
    if( pre1 < pre2 )
    {
        if( pre2 < e )
        {
            return e;
        }
        else
        {
            return pre2;
        }
    }
    else
    {
        if( pre1 < e )
        {
            return e;
        }
        else
        {
            return pre1;
        }
    }
}

int main()
{
    while( 1 )
    {
        int a = 0,b = 0,c = 0, d = 0,e = 0;
        int num1,num2;
        scanf( "%d %d\n", &num1, &num2 );
        if( num1 == 0 && num2 == 0 ) break;
        a += num1 + num2;
        scanf( "%d %d\n", &num1, &num2 );
        b += num1 + num2;
        scanf( "%d %d\n", &num1, &num2 );
        c += num1 + num2;
        scanf( "%d %d\n", &num1, &num2 );
        d += num1 + num2;
        scanf( "%d %d\n", &num1, &num2 );
        e += num1 + num2;
        int ma = max( a,b,c,d,e );
        if( ma == a )
        {
            printf( "A %d\n", a );
        }
        else if( ma == b )
        {
            printf( "B %d\n", b );
        }
        else if( ma == c )
        {
            printf( "C %d\n", c );
        }
        else if( ma == d )
        {
            printf( "D %d\n", d );
        }
        else if( ma == e )
        {
            printf( "E %d\n", e );
        }
    } 
    return 0;
}
