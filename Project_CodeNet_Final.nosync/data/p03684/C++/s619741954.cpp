#include <bits/stdc++.h>
#define Maxn 100007
using namespace std;
int n,x[Maxn],y[Maxn],cnt=0;
pair<int,int>p1[Maxn],p2[Maxn];
int last[Maxn],pre[Maxn*10],other[Maxn*10],dis[Maxn*10];
bool vis[Maxn];
int que[Maxn];
set<pair<int,int> >st;
set<pair<int,int> >::iterator it;
void insert(int u,int v,int len)
{
	other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
	dis[cnt]=len;
	other[++cnt]=u,pre[cnt]=last[v],last[v]=cnt;
	dis[cnt]=len;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	for (int i=1;i<=n;i++)
	{
		p1[i]=make_pair(x[i],i);
		p2[i]=make_pair(y[i],i);
	}
	memset(last,0,sizeof(last));
	sort(p1+1,p1+n+1);
	sort(p2+1,p2+n+1);
	for (int i=1;i<n;i++)
		insert(p1[i].second,p1[i+1].second,abs(p1[i].first-p1[i+1].first));
	for (int i=1;i<n;i++)
		insert(p2[i].second,p2[i+1].second,abs(p2[i].first-p2[i+1].first));
	memset(vis,false,sizeof(vis));
	long long ans=0;
	vis[1]=true;
	memset(que,0,sizeof(que));
	int lx=0,rx=1;
	que[1]=1;
	int t=1;
	st.clear();
	for (int i=1;i<n;i++)
	{
		for (int q=last[t];q;q=pre[q])
		{
			int v=other[q];
			if (!vis[v])
			{
				st.insert(make_pair(dis[q],v));
			}
		}
		it=st.begin();
		while (vis[(*it).second])
		{
			st.erase(it);
			it=st.begin();
		}
		t=(*it).second;
		vis[t]=true;
		que[++rx]=t;
		ans+=(*it).first;
		st.erase(it);
		++lx;
	}
	printf("%lld\n",ans);
	return 0;
}
