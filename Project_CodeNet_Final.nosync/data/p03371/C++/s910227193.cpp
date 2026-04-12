#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
//int a[10000];
int main()
{
	long long a,b,c,m,n;
	cin>>a>>b>>c>>m>>n;
	int ans=0;
	if(a+b>=2*c)
	{
		if(m>=n)
		{
			ans+=(n*2*c);
			if(a>=2*c)ans+=((m-n)*2*c);
			else ans+=((m-n)*a);
		}
		else 
		{
			ans+=(m*2*c);
			if(b>=2*c)ans+=((n-m)*2*c);
			else ans+=((n-m)*b);
		}
	}
	else
	{
		if(m>=n)
		{
			ans+=(n*(a+b));
			if(a>=2*c)ans+=((m-n)*2*c);
			else ans+=((m-n)*a);
		}
		else 
		{
			ans+=(m*(a+b));
			if(b>=2*c)ans+=((n-m)*2*c);
			else ans+=((n-m)*b);
		}
    }
    cout<<ans<<endl;
    return 0;
 } 