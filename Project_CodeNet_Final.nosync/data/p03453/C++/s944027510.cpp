#include<bits/stdc++.h>
#define N 200005
#define M 400005
#define ll long long
using namespace std;
const int p = 1000000007;
const int ni = 500000004;
int head[N],ver[M],nxt[M],tot,quan[M];
void add(int a,int b,int c)
{
	tot++;nxt[tot]=head[a];head[a]=tot;ver[tot]=b;quan[tot]=c;
}
int n,m,s,t;
ll dis1[N],f1[N],dis2[N],f2[N];
int q1[N],q2[N],in[N];
queue<int>q;
bool cmp1(int x,int y)
{
	return dis1[x]<dis1[y];
}
bool cmp2(int x,int y)
{
	return dis2[x]<dis2[y];
}
void spfa()
{
	memset(dis1,0x3f,sizeof(dis1));
	memset(dis2,0x3f,sizeof(dis2));
	dis1[s]=0;f1[s]=1;q.push(s);
	while(!q.empty())
	{
		int tmp=q.front();q.pop();
		in[tmp]=0;
		for(int i=head[tmp];i;i=nxt[i])
		{
			if(dis1[ver[i]]>dis1[tmp]+quan[i])
			{
				dis1[ver[i]]=dis1[tmp]+quan[i];
				if(!in[ver[i]])
				{
					in[ver[i]]=1;
					q.push(ver[i]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)q1[i]=i;
	sort(q1+1,q1+n+1,cmp1);
	for(int i=1;i<=n;i++)
	{
		for(int j=head[q1[i]];j;j=nxt[j])
		{
			if(dis1[ver[j]]==dis1[q1[i]]+quan[j])
			{
				(f1[ver[j]]+=f1[q1[i]])%=p;
			}
		}
	}
	
	
	dis2[t]=0;f2[t]=1;q.push(t);
	while(!q.empty())
	{
		int tmp=q.front();q.pop();
		in[tmp]=0;
		for(int i=head[tmp];i;i=nxt[i])
		{
			if(dis2[ver[i]]>dis2[tmp]+quan[i])
			{
				dis2[ver[i]]=dis2[tmp]+quan[i];
				if(!in[ver[i]])
				{
					in[ver[i]]=1;
					q.push(ver[i]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)q1[i]=i;
	sort(q1+1,q1+n+1,cmp2);
	for(int i=1;i<=n;i++)
	{
		for(int j=head[q1[i]];j;j=nxt[j])
		{
			if(dis2[ver[j]]==dis2[q1[i]]+quan[j])
			{
				(f2[ver[j]]+=f2[q1[i]])%=p;
			}
		}
	}
	
	ll ans=f1[t]*f1[t]%p;
//	cout<<ans<<endl;

	for(int i=1;i<=n;i++)
	{
		if(dis1[i]==dis2[i])ans=(ans-f1[i]*f1[i]%p*f2[i]%p*f2[i]%p+p)%p;
		for(int j=head[i];j;j=nxt[j])
		{
			if(dis1[ver[j]]==dis1[i]+quan[j]&&dis1[i]+dis2[ver[j]]+quan[j]==dis1[t])
			{
				if(dis1[i]<dis2[i]&&dis2[ver[j]]<dis1[ver[j]])
				{
					ans=(ans-f1[i]*f2[ver[j]]%p*f1[i]%p*f2[ver[j]]%p+p)%p;
				}
			}
		}
	}
	cout<<(ans%p+p)%p<<endl;
}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%d%d",&s,&t);
	int t1,t2,t3;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&t1,&t2,&t3);
		add(t1,t2,t3);add(t2,t1,t3);
	}
	spfa();
	return 0;
}