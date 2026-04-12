#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int stack[20];
inline void write(int x)
{
	if(x<0){putchar('-');x=-x;}
	if(!x){putchar('0');return;}
	int top=0;
	while(x)stack[++top]=x%10,x/=10;
	while(top)putchar(stack[top--]+'0');
}
inline void pr1(int x){write(x),putchar(' ');}
inline void pr2(int x){write(x),puts("");}
int a[200010];
long long cnt[2][2][200010],w[2][200010];
long long st[2][200010][20];
inline long long getmx(int id,int l,int r)
{
	bool pd=false;
	if(l==0)l=1,pd=true;
	if(l>r)return 0;
	int k = (int)(log((double)(r - l + 1)) / log(2.0));
	long long mx=max(st[id][l][k],st[id][r-(1<<k)+1][k]);
	if(pd==true)mx=max(mx,0LL);
	return mx;
}
inline long long solve(int l,int r)
{
	if(l==r)return 0;
	int d=r-l+1;
	if(d&1)
	{
		long long mx=solve(l,r-1);
		mx=max(mx,solve(l+1,r));
		if(l+2<=r-2)mx=max(mx,solve(l+2,r-2)+a[l]+a[r]);
		return mx;
	}
	else
	{
		if(l&1)return cnt[1][1][r/2]-cnt[1][0][(l-1)/2]+getmx(0,(l-1)/2,r/2);
		else return cnt[0][1][(r-1)/2]-cnt[0][0][l/2-1]+getmx(1,l/2-1,(r-1)/2);
	}
}
int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
   	int n=read(),now;
   	for(int i=1;i<=n;i++)a[i]=read();
   	now=0;
   	for(int i=1;i<=n;i+=2)
   	{
   		now++;
   		cnt[1][0][now]=cnt[1][0][now-1]+a[i];
   		cnt[1][1][now]=cnt[1][1][now-1]+a[i+1];
   		w[1][now]=cnt[1][0][now]-cnt[1][1][now];
   	}
   	for(int i=1;i<=now;i++)st[0][i][0]=w[1][i];
   	for(int i=1;(1<<i)<=now;i++)
   	{
   		for(int j=1;j+(1<<i)-1<=now;j++)st[0][j][i]=max(st[0][j][i-1],st[0][j+(1<<(i-1))][i-1]);
   	}
   	now=0;
   	for(int i=2;i<=n;i+=2)
   	{
   		now++;
   		cnt[0][0][now]=cnt[0][0][now-1]+a[i];
   		cnt[0][1][now]=cnt[0][1][now-1]+a[i+1];
   		w[0][now]=cnt[0][0][now]-cnt[0][1][now];   		
   	}
   	for(int i=1;i<=now;i++)st[1][i][0]=w[0][i];
   	for(int i=1;(1<<i)<=now;i++)
   	{
   		for(int j=1;j+(1<<i)-1<=now;j++)st[1][j][i]=max(st[1][j][i-1],st[1][j+(1<<(i-1))][i-1]);
   	}printf("%lld\n",solve(1,n));
    return 0;
}