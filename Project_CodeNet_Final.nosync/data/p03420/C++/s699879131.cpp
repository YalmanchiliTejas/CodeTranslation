#include<bits/stdc++.h>
using namespace std;

int read()
{
	int ans=0;
	char ch=getchar();
	for(;(ch<'0' || ch>'9') && ch!='-';ch=getchar());
	bool flag=false;
	if(ch=='-')
	{
		flag=true;
		ch=getchar();
	}
	for(;ch>='0' && ch<='9';ch=getchar())ans=ans*10+ch-'0';
	return flag?-ans:ans;
}

long long rell()
{
	long long ans=0;
	char ch=getchar();
	for(;(ch<'0' || ch>'9') && ch!='-';ch=getchar());
	bool flag=false;
	if(ch=='-')
	{
		flag=true;
		ch=getchar();
	}
	for(;ch>='0' && ch<='9';ch=getchar())ans=ans*10ll+(long long)(ch-'0');
	return flag?-ans:ans;
}

void write(int a)
{
	if(!a)
	{
		putchar('0');
		return;
	}
	static char ans[233];
	int n=0;
	for(;a;a/=10)ans[n++]=a%10+'0';
	for(;n;)putchar(ans[--n]);
}

void write(long long a)
{
	if(!a)
	{
		putchar('0');
		return;
	}
	static char ans[233];
	int n=0;
	for(;a;a/=10)ans[n++]=a%10+'0';
	for(;n;)putchar(ans[--n]);
}
const int N=1<<18;
int s[N],n;

void add(int i)
{
	for(;i<=n;i+=i&-i)s[i]++;
}

long long query(int i)
{
	int ans=0;
	for(;i;i-=i&-i)ans+=s[i];
	return ans;
}

int main()
{
	int m;
	scanf("%d%d",&n,&m);
	if(!m)
	{
		printf("%lld\n",(long long)n*n);
		return 0;
	}
	long long ans=0;
	for(int k=n;k>=m;k--)
	{
		ans+=query(n-k)+n-k;
		for(int i=k;i<=n;i+=k)add(i);
		//printf("k=%d ans=%lld\n",k,ans);
	}
	write(ans);
	return 0;
}
