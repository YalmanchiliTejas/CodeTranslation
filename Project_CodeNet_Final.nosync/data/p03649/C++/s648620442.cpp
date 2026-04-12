#include<bits/stdc++.h>
#include <unistd.h>
using namespace std;

#define sd(a) scanf("%d",&a)
#define ss(a) scanf("%s",a)
#define sl(a) scanf("%lld",&a)
#define clr(a) memset(a,0,sizeof(a))
#define debug(a) printf("check%d\n",a)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ll long long
#define N 60

ll a[N];
ll b[N];

int main()
{
	int n,i,j;
	sd(n);
	for(i=0;i<n;i++)
		sl(a[i]);
	ll ops=0;
	while(true)
	{
		clr(b);
		ll Sum=0;
		for(i=0;i<n;i++)
		{
			if(a[i]<n-1)	continue;
			ll diff=a[i]-n+1;
			ll q=diff/n;
			if(q*n<diff)
				q++;
			Sum+=q;
			b[i]=q;
			a[i]-=q*n;
		}
		ops+=Sum;
		for(i=0;i<n;i++)
			a[i]+=Sum-b[i];
		if(!Sum)	break;
	}
	printf("%lld\n",ops);
}