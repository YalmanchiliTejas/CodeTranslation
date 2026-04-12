//Love and Freedom.
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define ll long long
#define inf 20021225
#define N 110
#define pa pair<int,int>
#define mdn 1000000007
using namespace std;
int read()
{
	int s=0,t=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')	t=-1; ch=getchar();}
	while(ch>='0' && ch<='9')	s=s*10+ch-'0',ch=getchar();
	return s*t;
}
int a[N],n;
int ksm(int bs,int mi)
{
	int ans=1;
	while(mi)
	{
		if(mi&1)	ans=1ll*ans*bs%mdn;
		bs=1ll*bs*bs%mdn; mi>>=1;
	}
	return ans;
}
pa solve(int l,int r,int lim)
{
	int mn=a[min_element(a+l,a+r+1)-a],w1=1,w2=1,num=0;
	for(int i=l,j;i<=r;i++)
	{
		if(a[i]!=mn)
		{
			j=i; while(j+1<=r&&a[j+1]!=mn)	j++;
			pa cur=solve(i,j,mn); i=j;
			w1=1ll*cur.first*w1%mdn;
			w2=1ll*(cur.first+cur.second)%mdn*w2%mdn;
		}
		else	num++;
	}
	return make_pair(1ll*w1*ksm(2,mn-lim)%mdn,(1ll*w2*ksm(2,num)%mdn+1ll*w1*(ksm(2,mn-lim)-2)%mdn)%mdn);
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)	a[i]=read();
	printf("%d\n",solve(1,n,0).second);
	return 0;
}
