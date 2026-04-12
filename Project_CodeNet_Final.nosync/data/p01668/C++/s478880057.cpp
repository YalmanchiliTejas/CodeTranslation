#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const long long mod = 1e9+7;
long long ten[12345], last[12345];
long long solve( const char a[] , const int &n , const char b[] , const int &m ){
    long long ans = 0;
    if( m == 1 && b[0] == '0' )
        ans = 1;
    last[n] = 0;
    for( int i = n - 1 ; i >= 0 ; i -- )
        last[i] = ( last[i+1] + ten[n-i-1] * ( a[i] - '0' ) ) % mod;

    long long pre = 0;
    for( int i = 0, flag ; i < n ; i ++ ){
        if( i == 0 && b[0] == '0' && m == 1 ){
            pre = ( pre * 10LL + a[i] - '0' ) % mod;
            continue;
        }
        if( i + m > n )
            break;
        flag = 0;
        for( int j = 0 ; j < m ; j ++ ){
            if( a[i+j] < b[j] ){
                flag = -1;
                break;
            }else if( a[i+j] > b[j] ){
                flag = 1;
                break;
            }
        }
        if( flag > 0 )
            ans = ( ans + ( i == 0 ? 1LL : ( pre + mod - ( b[0] == '0' && m == 1 ) ) + 1 ) * ten[n-i-m] % mod ) % mod;
        else if( flag < 0 )
            ans = ( ans + ( i == 0 ? 0LL : ( pre + mod - ( b[0] == '0' && m == 1 ) ) ) % mod * ten[n-i-m] % mod ) % mod;
        else{
            ans = ( ans + ( i == 0 ? 0LL : ( pre + mod - ( b[0] == '0' && m == 1 ) ) ) % mod * ten[n-i-m] % mod ) % mod;
            ans = ( ans + last[i+m] + 1 ) % mod;
        }
        pre = ( pre * 10LL + a[i] - '0' ) % mod;
    }
    return ans;
}
char a[12345], b[12345], c[512];
int main(){

    ten[0] = 1;
    for( int i = 1 ; i <= 10000 ; i ++ )
        ten[i] = ten[i-1] * 10LL % mod;
    scanf( "%s %s %s" , a , b , c );
    int n = strlen( a ),
        m = strlen( b ),
        l = strlen( c );
    long long add = 0;

    for( int i = 0, flag ; i < n ; i ++ ){
        flag = 1;
        for( int j = 0 ; j < l ; j ++ ){
            if( a[i+j] != c[j] ){
                flag = 0;
                break;
            }
        }
        add += flag;
    }

    printf( "%lld\n" , ( solve( b , m , c , l ) - solve( a , n , c , l ) + mod + add ) % mod );
    return 0;
}