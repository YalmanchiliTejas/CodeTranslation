#include<iostream>
#include<cstdio>
using namespace std;
int r,l,a,f,t;
char o[10];
int main()
{
	int n,i,p,ans;
	while(scanf("%d",&n)&&n!=0)
	{
	a=1;f=2;r=3;l=4;t=5;ans=1;
	for(i=1;i<=n;i++)
	{
		scanf("%s",o);
		if(o[0]=='N')
		{
			t=a;a=f;f=7-t;
		}else if(o[0]=='S')
		{
			f=a;a=t;t=7-f;
		}else if(o[0]=='W')
		{
			l=a;a=r;r=7-l;
		}else if(o[0]=='E')
		{
			r=a;a=l;l=7-r;
		}else if(o[0]=='R')
		{
			p=l;
			l=f;
			f=r;
			r=t;
			t=p;
		}else if(o[0]=='L')
		{
			p=r;
			r=f;
			f=l;
			l=t;
			t=p;
		}
		ans+=a;
	}
	cout<<ans<<endl;
    }
	return 0;
	
}
