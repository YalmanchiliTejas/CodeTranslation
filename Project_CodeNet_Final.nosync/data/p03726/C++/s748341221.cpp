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
struct node
{
	int x,y,next;
}a[200010];int len,last[100010];
inline void ins(int x,int y)
{
	len++;
	a[len].x=x;a[len].y=y;
	a[len].next=last[x];last[x]=len;
}
int du[100010];
bool pd,id[100010];
inline void dfs(int x,int fa)
{
	int cnt=0;
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(y==fa)continue;
		dfs(y,x);
		if(id[y])cnt++;
	}
	if(cnt>=2)pd=true;
	if(!cnt)id[x]=1;
	if(!cnt && !fa)pd=true;
}
int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int n=read();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		ins(x,y),ins(y,x);du[x]++,du[y]++;
	}
	for(int i=1;i<=n;i++)if(du[i]>1){dfs(i,0);break;}
	if(pd==true)puts("First");
	else puts("Second");
	return 0;
}