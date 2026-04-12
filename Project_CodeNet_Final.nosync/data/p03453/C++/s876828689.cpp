#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>

template<typename T>inline bool check_min(T a,T &b){return a<b?b=a,1:0;}

namespace RongChi
{
	typedef long long ll;
	typedef std::pair<ll,int> pii;
	const int N=101000,M=N*4,MOD=1000000007;
	const ll INF=1000000000000000ll;
	inline void inc(int a,int &b){b=(a+b)%MOD;}

	int begin[N],next[M],to[M],w[M];
	int n,m,e;

	void work(int S,ll *dis,int *f)
	{
		static std::priority_queue<pii,std::vector<pii>,std::greater<pii> > Q;
		static bool vis[N];

		while(!Q.empty())Q.pop();
		for(int i=1;i<=n;i++)
			dis[i]=INF,f[i]=vis[i]=0;

		dis[S]=0,f[S]=1;
		Q.push(pii(0,S));

		for(int p,q;!Q.empty();)
		{
			p=Q.top().second,Q.pop();
			if(vis[p])continue;
			vis[p]=1;

			for(int i=begin[p];i;i=next[i])
			{
				if(check_min(dis[p]+w[i],dis[q=to[i]]))
					f[q]=f[p],Q.push(pii(dis[q],q));
				else if(dis[p]+w[i]==dis[q])
					inc(f[p],f[q]);
			}
		}
	}

	void add(int x,int y,int z,bool k=1)
	{
		to[++e]=y;
		next[e]=begin[x];
		begin[x]=e;
		w[e]=z;
		if(k)add(y,x,z,0);
	}

	int S,T;
	void initialize()
	{
		scanf("%d%d",&n,&m);
		scanf("%d%d",&S,&T);
		for(int i=1,u,v,k;i<=m;i++)
		{
			scanf("%d%d%d",&u,&v,&k);
			add(u,v,k);
		}
	}

	ll ds[N],dt[N];
	int fs[N],ft[N];

	int calc(int p)
	{
		return (ll)fs[p]*ft[p]%MOD*fs[p]%MOD*ft[p]%MOD;
	}
	int calc_e(int u,int v)
	{
		return (ll)fs[u]*ft[v]%MOD*fs[u]%MOD*ft[v]%MOD;
	}

	void solve()
	{
		initialize();
		work(S,ds,fs),work(T,dt,ft);

		ll len=ds[T];
		int ans=(ll)fs[T]*fs[T]%MOD;
		
		for(int p=1;p<=n;p++)
		{
			if(ds[p]*2==len)inc(-calc(p),ans);

			for(int i=begin[p],q;i;i=next[i])
			{
				q=to[i];
				if(ds[p]*2<len && dt[q]*2<len && ds[p]+dt[q]+w[i]==len)
				{
					inc(-calc_e(p,q),ans);
				}
			}
		}

		ans=(ans+MOD)%MOD;

		printf("%d\n",ans);
		
	}
}

int main()
{
//	freopen("in","r",stdin);
	RongChi::solve();
	return 0;
}
