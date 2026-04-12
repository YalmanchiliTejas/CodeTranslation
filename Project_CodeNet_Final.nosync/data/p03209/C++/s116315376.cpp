#include<bits/stdc++.h>
using namespace std;
long long a[51];
long long s[51];
long long fun(int l,long long x)
{
	if(x==0)
		return 0;
	else if(l==0)
		return 1;
	else if(x>=a[l])
		return s[l];
	long long sum=0,t2;
	int t1;
	t1=l;
	t2=x;
	x--;
	sum+=fun(l-1,min(a[l-1],x));
	x-=a[l-1];
	if(x>0)
	{
		x--;
		sum++;
	}
	if(x>0)
		sum+=fun(l-1,min(a[l-1],x));
	//printf("%d %lld %lld\n",t1,t2,sum);
	return sum;
}
int main()
{
	int n,i;
	long long x;
	scanf("%d %lld",&n,&x);
	s[0]=a[0]=1;
	for(i=1;i<=n;i++)
	{
		s[i]=s[i-1]*2+1;
		a[i]=a[i-1]*2+3;
		//printf("%d %lld %lld\n",i,a[i],s[i]);
	}
	printf("%lld",fun(n,x));
	return 0;
}