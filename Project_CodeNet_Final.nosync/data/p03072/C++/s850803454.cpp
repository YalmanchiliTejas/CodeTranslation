# include <bits/stdc++.h>

using namespace std ;

int n, x, mx, ans;

int main() {
   cin >> n ;
   for( int i = 0 ; i < n ; i ++ ) {
        cin >> x ;
        if( x >= mx ) {
            mx = x ;
            ans ++ ;
        }
   }
   cout << ans << endl;
}
