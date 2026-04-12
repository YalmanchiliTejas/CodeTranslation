#include<iostream>
using namespace std;
int c[10001];
int y[100];
int n,a,b,C,x;
main()
{
	while(cin>>n>>a>>b>>C>>x,n)
	{
		for(int i=0;i<n;i++)cin>>y[i];
		int ans=0;
		bool flag=0;
		for(int i=0;i<n;i++)
		{
			for(int i=0;i<=10000;i++)c[i]=0;
			while(x!=y[i]&&!c[x])
			{
				ans++;
				c[x]=1;
				x=(a*x+b)%C;
			}
			if(x!=y[i]||ans>10000)
			{
				flag=1;
				break;
			}
			if(i!=n-1)x=(a*x+b)%C,ans++;
		}
		cout<<(flag?-1:ans)<<endl;
	}
}

