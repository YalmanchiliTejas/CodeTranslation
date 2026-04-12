#include <bits/stdc++.h>
#define intt long long
using namespace std;
int i , j ;
int main ()
{
    int n,m;
    cin >> n >> m;
    char c[n+1][m+1];
    for ( i = 1 ; i <= n ; i++ )
    {
        for ( j =1 ; j <= m ; j++ )
        {
            cin >> c[i][j];
        }
    }
    for ( i = 1 ; i <= n ; i++ )
    {
        for ( j =1  ; j <= m ; j++ )
        {
            if ( c[i][j] == '#' )
                break;
        }
        if ( j == m+1 )
        {
            for ( j = 1 ;  j<= m ; j++ )
            {
                c[i][j] = '1';
            }
        }
    }
    for ( i =1 ; i <= m ; i++ )
    {
        for ( j =1 ;  j<= n ; j++ )
        {
            if ( c[j][i] == '#' )
                break;
        }
        if ( j == n+1 )
        {
            for ( j =1 ;  j<= n ; j++ )
            {
                c[j][i] = '1';
            }
        }
    }
    for ( i =1 ;  i<= n ; i++ )
    {
        bool flag = false;
        for ( j =1 ;  j <= m ; j++ )
        {
            if ( c[i][j] == '1' )
                continue;
            cout << c[i][j];
            flag = 1;
        }
        if ( flag )
            cout << endl;
    }
}
