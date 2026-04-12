#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define FAST_IO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define endl "\n"
#define PI 3.14159265358979323846264338327950288
 
using namespace std ;
using bigint = long long int ;
using vi = vector<int> ;
using vll = vector<long long int> ;

bigint suffix[200005] ;
int main(){
    FAST_IO ;
    int N ; cin >> N ;
    bigint arr[N+3] ;
    for( int i = 0 ; i < N ; i++ )
        cin >> arr[i] ;
    suffix[N] = 0 ;
    for( int i = N - 1 ; i >= 0 ; i-- ){
        suffix[i] = (suffix[i+1] + arr[i]) % mod ;
    }
    bigint ans = 0 ;
    for( int i = 0 ; i < N ; i++ ){
        bigint c = (arr[i] % mod * suffix[i+1]) % mod ;
        ans = ( ans + c ) % mod ;
    }
    cout << ans << endl ;
    return 0 ;
    
}
 
 
 