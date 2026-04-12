#include <bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;
inline int read()
{int x=0,f=0;
char c=getchar();
while (c<'0'||c>'9') 
{if (c=='-') f=1;
c=getchar();
}
while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
if (f) x=-x;
return x;
}
int a[100005],b[100005],n,m,st,ed;
ll da[100005],db[100005];
priority_queue <pair<ll,int> > q;
int head[100005],nxt[400005],u[400005],v[400005],w[400005],o[400005],tot=0;
inline void add(int a,int b,int c)
{tot++;nxt[tot]=head[a];head[a]=tot;v[tot]=b;u[tot]=a;w[tot]=c;}
inline void work1()
{memset (da,0x2f,sizeof(da));
da[st]=0;a[st]=1;
q.push(make_pair(0,st));
while (!q.empty())
{int t=(q.top()).second;
ll d=-(q.top()).first;
q.pop();
if (da[t]!=d) continue;
for (int i=head[t];i;i=nxt[i])
{if (da[v[i]]>da[t]+w[i])
{da[v[i]]=da[t]+w[i];a[v[i]]=a[t];
q.push(make_pair(-da[v[i]],v[i]));
}
else
{if (da[v[i]]==da[t]+w[i]) 
{a[v[i]]+=a[t];
if (a[v[i]]>=mod) a[v[i]]-=mod;
}
}
}
}
}
inline void work2()
{memset (db,0x2f,sizeof(db));
db[ed]=0;b[ed]=1;
q.push(make_pair(0,ed));
while (!q.empty())
{int t=(q.top()).second;
ll d=-(q.top()).first;
q.pop();
if (db[t]!=d) continue;
for (int i=head[t];i;i=nxt[i])
{if (db[v[i]]>db[t]+w[i])
{db[v[i]]=db[t]+w[i];b[v[i]]=b[t];
q.push(make_pair(-db[v[i]],v[i]));
}
else
{if (db[v[i]]==db[t]+w[i]) 
{b[v[i]]+=b[t];
if (b[v[i]]>=mod) b[v[i]]-=mod;
}
}
}
}
}
int main (){
	int i,j,k,ta,tb,tc;
	n=read();m=read();
	st=read();ed=read();
	for (i=1;i<=m;i++)
	{ta=read();tb=read();tc=read();
	add(ta,tb,tc);add(tb,ta,tc);
	}
	work1();work2();
	int num=a[ed],ans=1ll*num*num%mod;
	for (i=1;i<=n;i++)
	{if (da[i]+db[i]==da[ed]&&da[i]==db[i])
	{int ways=1ll*a[i]*b[i]%mod;
	ans-=1ll*ways*ways%mod;
	if (ans<0) ans+=mod;
	}
	}
	for (i=1;i<=tot;i++)
	{if (da[u[i]]+w[i]+db[v[i]]==da[ed])
	{if (da[u[i]]*2ll<da[ed]&&db[v[i]]*2ll<da[ed])
	{int ways=1ll*a[u[i]]*b[v[i]]%mod;
	ans-=1ll*ways*ways%mod;
	if (ans<0) ans+=mod;
	}
	}
	}
	printf ("%d\n",ans);
	return 0;
}
	
	
	