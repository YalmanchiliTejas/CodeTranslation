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
ll mem[102][4][2];
char al[102];
ll dp  (int i , int kk , int f ) {

if ( i == n ) {
    return !kk;
}
ll &ret = mem[i][kk][f];
if ( ret != -1 ) return ret ;
ret = 0 ;

for ( int d = 1 ; kk && d <= ( f ? 9 : int(al[i]-'0')) ;d++) {
    ret += dp (i+1, kk-1, f | (d<(al[i]-'0')));
}
ret += dp (i+1, kk , f | ( 0<(al[i]-'0')) );

return ret ;
}
int main ( ){
  scanf("%s",al);
  n=strlen(al);
  scanf("%d",&k);
  memset( mem , -1, sizeof mem );
  printf("%lld\n",dp(0,k,0));
return 0 ;
}
