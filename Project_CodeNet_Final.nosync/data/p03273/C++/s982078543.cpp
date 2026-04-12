#include<bits/stdc++.h>
using namespace std;
namespace FAST_IO
{
	template<typename T> void read(T &a)
	{
		a=0;
		int f=1;
		char c=getchar();
		while(!isdigit(c))
		{
			if(c=='-')
			{
				f=-1;
			}
			c=getchar();
		}
		while(isdigit(c))
		{
			a=a*10+c-'0';
			c=getchar();
		}
		a=a*f;
	}
	template <typename T> void write(T a)
	{
		if(a<0)
		{
			a=-a;
			putchar('-');
		}
		if(a>9)
		{
			write(a/10);
		}
		putchar(a%10+'0');
	}
	template <typename T> void writeln(T a)
	{
		write(a);
		puts("");
	}
}	
bool u[101];
int main()
{
	int h,w;
	cin>>h>>w;
	string s[101],q="";
	for(int i=1;i<=w;i++)
	{
		q+='.';
	}
	int zz=1;
	for(int i=1;i<=h;i++)
	{
		cin>>s[zz];
		if(s[zz]!=q)
		{
			zz++;
		}
	}
	for(int i=0;i<w;i++)
	{
		for(int j=1;j<zz;j++)
		{
			if(s[j][i]!='.')
			{
				goto A;
			}
		}
		u[i]=true;
		A:
		continue;
	}
	for(int i=1;i<zz;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(u[j])
			{
				continue;
			}
			cout<<s[i][j];
		}
		cout<<endl;
	}
}