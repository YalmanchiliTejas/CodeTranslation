#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int a,b,c,m,n,f,sum=0;
	cin>>a>>b>>c>>m>>n;
	if(a+b>=2*c) f=2*c;
	else f=a+b;
	if(m>=n)
	{
		sum+=n*f;
		m-=n;
		n=0;
		if(a>=2*c)
		{
			sum+=m*2*c;
		}
		else
		{
			sum+=m*a;
		}
	}
	else
	{
		sum+=m*f;
		n-=m;
		m=0;
		if(b>=2*c)
		{
			sum+=n*2*c;
		}
		else
		{
			sum+=n*b;
		}
	}
	cout<<sum;
}