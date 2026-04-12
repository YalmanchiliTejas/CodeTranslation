#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std ;

int h[1000] ;
int n ;
int res ;

int main ()
{
	int i ;
	scanf("%d",&n);
	for ( i=1 ; i<=n ; i++ ) scanf("%d",h+i);
	res=1 ;
	for ( i=2 ; i<=n ; i++ ) 
	{
		if ( h[i]>=h[i-1] ) res++;
		h[i]=max(h[i],h[i-1]);
	}
	printf("%d\n",res);
	return 0 ;
}