#include <bits/stdc++.h>
using namespace std ;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

const ll mod = 1e9 + 7 ;
int main(){
 ll n ;
 cin >> n ;
 vector<ll> A(n) ;
 rep(i,n) cin >> A.at(i) ;
 ll sum = 0 ;
 ll ans = 0 ;
 rep(i,n){
     sum += A.at(i) ;
 } 
rep(i,n){
    sum -= A.at(i) ;
    ll tem = sum % mod ;
    ans += (A.at(i)*tem)%mod ;
    ans %= mod ;
}
cout << ans << endl; 
} 