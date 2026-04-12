#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read()
{
	int out=0,fh=1;
	char jp=getchar();
	while ((jp>'9'||jp<'0')&&jp!='-')
		jp=getchar();
	if (jp=='-')
		fh=-1,jp=getchar();
	while (jp>='0'&&jp<='9')
		out=out*10+jp-'0',jp=getchar();
	return out*fh;
}
const int MAXN=1e5+10;
int n,A[MAXN],a[MAXN];
#define lowbit(x) x&(-x)
int bit[MAXN];
void add(int x,int c)
{
	for(;x<=n;x+=lowbit(x))
		bit[x]=max(bit[x],c);
}
int sum(int x)
{
	int s=0;
	for(;x;x-=lowbit(x))
		s=max(s,bit[x]);
	return s;
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
		A[i]=a[i]=read();
	sort(A+1,A+1+n);
	int m=unique(A+1,A+1+n)-A-1;
	for(int i=1;i<=n;++i)
	{
		int x=lower_bound(A+1,A+1+m,a[i])-A;
		x=m+1-x;
		int y=sum(x)+1;
		add(x,y);
	}
	cout<<sum(n)<<endl;
	return 0;
}
