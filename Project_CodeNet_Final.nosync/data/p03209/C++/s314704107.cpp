#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std ;

#define R register
typedef long long LL ;

LL f[60];
LL len[60];
int n ;
LL k ;

inline LL tryy ( int n , LL k )
{
	R LL L=len[n]/2+1;
	if ( n==0 ) return 1;
	if ( k==1 ) return 0 ;
	if ( k<L ) return tryy(n-1,k-1);
	else if ( k==L ) return tryy(n-1,k-1)+1;
	else if ( k>L ) return f[n-1]+tryy(n-1,k-len[n-1]-2)+1;
	return 0 ;
}

int main ()
{
	int i ;
	scanf("%d%lld",&n,&k);
	len[0]=1;
	for ( i=1 ; i<=n ; i++ ) len[i]=len[i-1]*2+3;
	f[0]=1;
	for ( i=1 ; i<=n ; i++ ) f[i]=f[i-1]*2+1;
	printf("%lld\n",tryy(n,k));
	return 0 ;
}