#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    long long n = 0 ; 
    cin >> n ; 
    bool maximize = !(n&1) ;
    long long a[n+1] , diff[n+1][n+1] ;
    a[0] = 0 ;
    for(long long i = 1 ; i <= n ; i++)
        cin >> a[i] ;
    for(long long i = 0 ; i <= n ; i++)
        for(long long j = 0 ; j <= n ; j++)
            diff[i][j] = 0 , diff[1][j] = a[j] ;
    for(long long i = 1 ; i <= n-2+1 ; i++){
        if(maximize) diff[2][i] = max(a[i+1]-a[i], a[i]-a[i+1]) ;
        else diff[2][i] = min(a[i+1]-a[i], a[i]-a[i+1]) ;
    }
    maximize = !maximize ;
    for(long long L = 3 ; L <= n ; L++){
        for(long long i = 1 ; i <= n-L+1 ; i++){
            if(maximize) diff[L][i] = max(a[i] + diff[L-1][i+1] , a[L+i-1] + diff[L-1][i]) ;
            else diff[L][i] = min(-a[i] + diff[L-1][i+1] , -a[L+i-1] + diff[L-1][i]) ;
        }
        maximize = !maximize ;
    }
    cout << diff[n][1] ;
}
