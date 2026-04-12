#include <bits/stdc++.h>
using namespace std ;

int main() 
{
    ios::sync_with_stdio(0); 
    int x , y , z ;
    int res = 0 ;
    cin >> x >> y >> z ;
    x -= z ;
    while ( x >= (y+z) ) 
    {
        x -= (y+z) ; 
        res++ ; 
    }
    cout << res << endl ; 
    return 0 ; 
}