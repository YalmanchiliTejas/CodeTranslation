#include<bits/stdc++.h>
using namespace std ;

const int N = 2e5 + 10 ;

int main() {
    int tot , y , gap , ans = 0 ;
    scanf("%d %d %d" , &tot , &y , &gap ) ;
    for( int i = 1 ; ; i++ ) {
        if( (i+1)*gap + (i*y) > tot ) break ;
        ans = i ;
    }
    cout << ans << endl ;
    return 0 ;
}
