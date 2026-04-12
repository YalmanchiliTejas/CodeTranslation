#include <algorithm>
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std ;

const int MAXN=1e5+100;

int a[MAXN];
int p[MAXN];
int n ;

int main ()
{
	int i , j , k ;
	scanf("%d",&n);
	for ( i=1 ; i<=n ; i++ ) scanf("%d",p+i);
	sort(p+1,p+n+1);
	long long res=0,ans=0;
	int flag=1;
	a[(n+1)>>1]=p[n];
	for ( k=1 , i=1 , j=n-1 ; i<j ; k++ ) 
	{
		if ( flag ) a[((n+1)>>1)-k]=p[i],a[((n+1)>>1)+k]=p[i+1],i+=2;
		else a[((n+1)>>1)-k]=p[j-1],a[((n+1)>>1)+k]=p[j],j-=2;
		flag=1-flag;
	}
	if ( ~n&1 ) a[n]=p[(n+1)>>1];
	for ( i=2 ; i<=n ; i++ ) res+=(long long)abs(a[i]-a[i-1]);
	// printf("%lld\n",res);
	flag=0;
	a[(n+1)>>1]=p[1];
	for ( k=1 , i=2 , j=n ; i<j ; k++ )
	{
		if ( flag ) a[((n+1)>>1)-k]=p[i],a[((n+1)>>1)+k]=p[i+1],i+=2;
		else a[((n+1)>>1)-k]=p[j-1],a[((n+1)>>1)+k]=p[j],j-=2;
		flag=1-flag;
	}
	if ( ~n&1 ) a[n]=p[(n+1)>>1];
	for ( i=2 ; i<=n ; i++ ) ans+=(long long)abs(a[i]-a[i-1]);
	res=max(res,ans);
	printf("%lld\n",res);
	return 0 ;
}