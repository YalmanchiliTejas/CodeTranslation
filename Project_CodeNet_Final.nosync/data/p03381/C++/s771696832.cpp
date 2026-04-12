#include<bits/stdc++.h>
using namespace std ;
struct fuck{
       int val , id ;
}f[200010] ;
bool cmp( fuck a , fuck b ) { return a.val < b.val ; }
int x[200010] ;
int main(){
    int n ;
    cin >> n ;
    for( int i = 1 ; i <= n ; i++ ){
        f[i].id = i ;
        scanf( "%d" , &f[i].val ) ;
    }
    sort( f + 1 , f + 1 + n , cmp ) ;
    for( int i = 1 ; i <= n ; i++ )
        x[f[i].id] = i ;
    int A = f[n / 2].val ;
    int B = f[n / 2 + 1].val ;
    for( int i = 1 ; i <= n ; i++ ){
        if ( x[i] <= n / 2 ) printf( "%d\n" , B ) ;
        else printf( "%d\n" , A ) ;
    }
    return 0 ;
}