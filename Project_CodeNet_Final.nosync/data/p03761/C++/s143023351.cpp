#include <bits/stdc++.h>
using namespace std ;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

//ll gcd(int a, int b){ return b? gcd(b,a%b) : a ; } 

int main(){
    int n ;
    cin >> n ;
    int A[n][26] ;
    //char l = 'a' + 1 ;
    fill(A[0],A[n],0) ;
    rep(i,n){
        string s ;
        cin >> s ;
        rep(j,s.size()){
            int k = s[j] - 'a' ;
            A[i][k]++ ; 
        }
    }
    rep(i,26){
        int count = 1e9 ;
        rep(j,n){
            count = min(count,A[j][i]) ;
        }
        rep(k,count){
            char l = 'a' + i ;
            cout <<  l ;
        } 
    }
}