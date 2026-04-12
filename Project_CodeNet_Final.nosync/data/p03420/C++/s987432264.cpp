/**
*
* Author: Mouhanad
* Lang: GNU C++14
*
**/
#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ii pair < int , int >
#define LS pair < ll , string >
typedef long long ll;
const int inf = 1<<30;
const int N =100100;
int n , a[N] , k ;

int main ( ){
 scanf("%d %d",&n,&k);
 if ( k == 0 ){
    printf("%lld",1LL*n*n);
    return 0 ;
 }
 /*if ( k == 1 ){
     printf("%lld",(1LL*n*n)-n);
    return 0 ;

 }*/

 ll ANS =0  ;
 for ( int i = k ; i <= n-1 ; i ++ ){
    ANS += (n-i);
 }
 for ( int i = k+1 ; i <= n-1 ; i ++ ){
    int add = n/i ;

    add-- ;
    if ( add  < 0 ) add = 0 ;
    ANS += (1LL*add*(i-k)) ;
    int rem = n%i ;
    if ( rem < k ) continue ;
    ANS += (rem-k+1);
 }
 printf("%lld",ANS);
return 0 ;
}
