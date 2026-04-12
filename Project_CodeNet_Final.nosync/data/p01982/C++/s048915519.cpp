#include <bits/stdc++.h>
using namespace std;

#define FOR( i, m, n )  for( int (i) = (m); (i) < (n); (i)++ )
#define REP( i, n )     FOR( i, 0, n )
#define ALL( a )        (a).begin(), (a).end()             

int main(void){
    int n, l, r;
    
    while( 1 ){
        cin >> n >> l >> r;
        if( n == 0 && l == 0 && r == 0 ) break;
        vector<int> a(n);
        REP( i, n ) cin >> a[i];
        
        int cnt = 0;
        FOR( i, l, r + 1 ){
            REP( j, n ){
                if( i % a[j] == 0 && ( ( j + 1 ) % 2 ) == 1 ){
                    cnt++;
                    break;
                }
                if( i % a[j] == 0 && ( ( j + 1 ) % 2 ) == 0 ){
                    break;
                }
                
                if( ( j == n - 1 ) && n % 2 == 0 ){
                    cnt++;
                } 
            }
        }
        
        cout << cnt << endl;
        
    }
    


}
