#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
inline void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
inline void pr1(int x){write(x),putchar(' ');}
inline void pr2(int x){write(x),puts("");}
struct node
{
	int d,p;
}a[100010];
bool cmp(node a,node b){return a.d<b.d;}
int now,ex[100010];
int s[100010];
inline int lowbit(int x){return x&-x;}
inline void change(int x,int d)
{
	while(x<=now)
	{
		s[x]=max(s[x],d);
		x+=lowbit(x);
	}
}
inline int getmx(int x)
{
	int mx=0;
	while(x>=1)
	{
		mx=max(mx,s[x]);
		x-=lowbit(x);
	}return mx;
}
int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n=read();
    for(int i=1;i<=n;i++)a[i].d=read(),a[i].p=i;
    sort(a+1,a+n+1,cmp);
    a[0].d=-1;
    for(int i=1;i<=n;i++)
	{
		if(a[i].d!=a[i-1].d)now++;
		ex[a[i].p]=now;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ex[i]=now-ex[i]+1;
		int uf=getmx(ex[i])+1;
		ans=max(ans,uf);change(ex[i],uf);
	}pr2(ans);
    return 0;
}