#include <bits/stdc++.h>
using namespace std;

/*

dp[i][j] after consider i the last select is j

select i
dp[i][i] = \max_{j} dp[i-1][j] + \sum_{j<l[k]<=i && r[k]>=i} a[k]
for i add l[k]==i to [0,l[k]-1]
      remove all r[k]==i-1 from [0,l[k]-1]

not select i
dp[i][j] = dp[i-1][j]

*/

typedef long long LL;
typedef pair<int,int> PII;
const int M=2e5+5;
const LL NLINF=0x8080808080808080;
LL dp[M]; // select i the max profit
vector<PII> lset[M];
vector<PII> rset[M];

struct SegT
{
	LL mx[M*2],add[M*2];
	int ML,MR;
	void build(int o,int l,int r)
	{
		mx[o]=NLINF;
		add[o]=0;
		if(l==r) return;
		int mid=(l+r)>>1;
		int ls=o+1,rs=o+((mid-l+1)<<1);
		build(ls,l,mid);
		build(rs,mid+1,r);
	}
	
	void push(int o,int ls,int rs)
	{
		if(add[o])
		{
			add[ls]+=add[o];
			mx[ls]+=add[o];
			add[rs]+=add[o];
			mx[rs]+=add[o];
			add[o]=0;
		}
	}
	void pull(int o,int ls,int rs)
	{
		mx[o]=max(mx[ls],mx[rs]);
	}
	LL V,L,R;
	void update_(int o,int l,int r)
	{
		if(L<=l&&r<=R)
		{
			mx[o]+=V;
			add[o]+=V;
			return;
		}
		int mid=(l+r)>>1;
		int ls=o+1,rs=o+((mid-l+1)<<1);
		push(o,ls,rs);
		if(L<=mid) update_(ls,l,mid);
		if(mid<R) update_(rs,mid+1,r);
		pull(o,ls,rs);
	}
	void update(int l,int r,LL v)
	{
		//cout<<"U "<<l<<" "<<r<<" "<<v<<endl;
		L=l; R=r; V=v;
		update_(0,ML,MR);
	}
	LL query_(int o,int l,int r)
	{
		if(L<=l&&r<=R)
			return mx[o];
		int mid=(l+r)>>1;
		int ls=o+1,rs=o+((mid-l+1)<<1);
		push(o,ls,rs);
		LL ans=NLINF;
		if(L<=mid) ans=max(ans,query_(ls,l,mid));
		if(mid<R) ans=max(ans,query_(rs,mid+1,r));
		pull(o,ls,rs);
		return ans;
	}
	LL query(int l,int r)
	{
		//cout<<"Q "<<l<<" "<<r;
		L=l; R=r;
		LL ans=query_(0,ML,MR);
		//cout<<" = "<<ans<<endl;
		return ans;
	}
	void show(int o,int l,int r)
	{
		cout<<mx[o]<<" "<<l<<" "<<r<<endl;
		if(l==r) return;
		int mid=(l+r)>>1;
		int ls=o+1,rs=o+((mid-l+1)<<1);
		show(ls,l,mid);
		show(rs,mid+1,r);
	}
}segt;

int main()
{
	//freopen("W.in","r",stdin);
	int n,m; scanf("%d%d",&n,&m);
	int li,ri,ai;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&li,&ri,&ai);
		lset[li].push_back({ri,ai});
		rset[ri].push_back({li,ai});
	}
	memset(dp,0x80,sizeof(dp));
	//cout<<dp[0]<<" "<<NLINF<<endl;
	dp[0]=0;
	segt.build(0,0,n);
	segt.ML=0; segt.MR=n;
	segt.update(0,0,-NLINF);
	//segt.show(0,0,n);
	for(int i=1;i<=n;i++)
	{
		//cout<<endl<<"!!!!!! "<<i<<endl;
		for(auto p:lset[i])
			segt.update(0,i-1,p.second);
		for(auto p:rset[i-1])
			segt.update(0,p.first-1,-p.second);
		//cout<<endl;
		//segt.show(0,0,n);
		LL pdp=dp[i];
		dp[i]=segt.query(0,i-1);
		segt.update(i,i,dp[i]-pdp);
		// cout<<dp[i]<<endl;
		// for(int i=0;i<=n;i++)
		// 	cout<<dp[i]<<" ";
		// cout<<endl;
	}
	LL ans=NLINF;
	for(int i=0;i<=n;i++)
		ans=max(ans,dp[i]);
	printf("%lld\n",ans);
	return 0;
}