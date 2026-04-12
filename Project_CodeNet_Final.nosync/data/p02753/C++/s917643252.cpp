#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define mem(f, x) memset(f, x, sizeof(f))
#define INF 0x3f3f3f3f
using namespace std;
const int M = 15;
const int N = 10005;
char s[N];
int main( ){
    while( scanf( "%s", s ) != EOF ){
        int len = strlen( s );
        int flag = 0;
        for( int i = 1; i < len; i++ )
            if( s[i-1] != s[i] ){
                flag = 1;
                break;
            }
        if( flag )
            printf( "Yes\n" );
        else
            printf( "No\n" );
    }
    return 0;
}
