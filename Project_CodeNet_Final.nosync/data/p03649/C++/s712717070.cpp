#include<bits/stdc++.h>
using namespace std;

int read()
{
	int ans=0;
	char ch=getchar();
	for(;(ch<'0' || ch>'9') && ch!='-';ch=getchar());
	bool flag=0;
	if(ch=='-')flag=1,ch=getchar();
	for(;ch>='0' && ch<='9';ch=getchar())ans=ans*10+ch-'0';
	if(flag)ans=-ans;
	return ans;
}

long long rell()
{
	long long ans=0;
	char ch=getchar();
	for(;(ch<'0' || ch>'9') && ch!='-';ch=getchar());
	bool flag=0;
	if(ch=='-')flag=1,ch=getchar();
	for(;ch>='0' && ch<='9';ch=getchar())ans=ans*10ll+(long long)(ch-'0');
	if(flag)ans=-ans;
	return ans;
}

void writ(int n)
{
	char ch[25];
	int m=0;
	if(n<0)putchar('-'),n=-n;
	if(n==0)
	{
		putchar('0');
		return;
	}
	for(;n;n/=10)ch[m++]=n%10ll+'0';
	for(;m;)putchar(ch[--m]);
}

void wrll(long long n)
{
	char ch[25];
	int m=0;
	if(n<0)putchar('-'),n=-n;
	if(n==0)
	{
		putchar('0');
		return;
	}
	for(;n;n/=10ll)ch[m++]=n%10ll+'0';
	for(;m;)putchar(ch[--m]);
}

const int N=1<<9;
long long a[N];
int n;

bool check(long long k)
{
	if(k<0)return true;
	long long sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=(a[i]+k)/(long long)(n+1);
	}
	return sum>=k;
}

int main()
{
	n=read();
	for(int i=0;i<n;i++)
	{
		a[i]=rell();
	}
	long long h=0,t=1e18;
	for(;h<=t;)
	{
		long long mid=(h+t)>>1;
		bool flag=true;
		for(long long i=0;i<=n;i++)
		{
			flag&=check(mid-i);
		}
		if(flag)h=mid+1ll;else t=mid-1ll;
	}
	wrll(t);puts("");
	return 0;
}
