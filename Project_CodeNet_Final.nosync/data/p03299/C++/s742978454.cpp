	#include <iostream>
    #include <string>
    #include <set>  
    #include <stack>
    #include <algorithm>
    #include <vector>
    #include <cmath>
    #include <queue>
    #include <deque>
    #include <cstring>
    #include <cstdio>
    #include <map>
    #include <numeric>
    #include <cassert>
    #include <iomanip>
    #include <sstream>
    #include <ctime>
    #include <bitset> 
using namespace std;
#define for1(i,a,b) for(int i=(a);i<(int)(b);++i)
#define rep(i,maxn) for1(i,0,maxn)
#define ford(i,b,a) for(int i=(int)(b)-1;i>=a;--i)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii > piii;
#define inf 0x3f3f3f3f
#define mod 1000000007
#define st first
#define nd second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define dprintf(...) printf(__VA_ARGS__)
const int maxn=110;
ll h[maxn];
ll ncnt;
int n;
vector<pii> dive;
ll qp(ll base,ll ind)
{
	ll ans=1;
	if(ind<0)cout<<"Wrong"<<endl;
	while(ind>0)
	{
		if(ind&1)ans=ans*base%mod;
		ind>>=1;
		base=base*base%mod;
	}
	return ans%mod;
}
ll f[maxn],g[maxn];
ll cal(int bg,int ed)
{
	f[bg]=qp(2,h[bg]-1);
	g[bg]=1;
	for1(i,bg,ed)
	{
	//	cout<<i<<" "<<f[i]<<" "<<g[i]<<endl;
	//	system("pause");
		if(h[i+1]>=h[i])
		{
			ll buf=qp(2,h[i+1]-h[i]);
			f[i+1]=(f[i]+g[i])%mod*buf%mod;
			g[i+1]=g[i]*2%mod;
		}
		else
		{
			ll rst=qp(2,h[i]-h[i+1])-1;
		//	cout<<rst<<endl;
			ll res=0;
			ll buf=1;
			f[i+1]=(f[i]+g[i])%mod;
			int cur=i;ll mx=h[i];ll pre=h[i];
			while(rst>0&&cur>bg)
			{
				cur--;
				if(h[cur]==pre)continue;
				if(h[cur]>pre)
				{
					buf=buf*qp(2,h[cur]-pre)%mod;
					pre=h[cur];
				//	cout<<cur<<" "<<buf<<endl;
				//	system("pause");
					continue;
				} 
				if(h[cur]<=h[i+1])
				{
					res+=rst*2%mod*g[cur]%mod*buf%mod;
					res%=mod;
			//		cout<<res<<endl;
					buf=0;rst=0;
					break;
				}
				pre=h[cur];
				if(h[cur]>=mx)continue;
			//	cout<<h[i]<<" "<<mx<<" "<<h[cur]<<endl;
				ll ok=qp(2,h[i]-h[cur])-qp(2,h[i]-mx);
				if(ok<0)ok=(ok+mod)%mod;
				res+=g[cur]*2*ok%mod*buf%mod;
				rst=((rst+mod)-ok)%mod;
			//	cout<<ok<<" "<<rst<<" "<<res<<endl;
			//	system("pause");
				mx=h[cur];
			}
		//	if(buf<0)cout<<"Error"<<endl;
			res=(res+rst*buf%mod)%mod;
			f[i+1]+=res;
			f[i+1]%=mod;
			g[i+1]=(res+g[i])*2%mod;
		//	cout<<res<<" "<<buf<<" "<<f[i+1]<<" "<<g[i+1]<<endl;
		}
	}
	return f[ed]%mod;
}
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%lld",h+i);
	int stp=0,edp=-1;
	rep(i,n)
	{
		ll pre=(i?h[i-1]:1);
		ll nxt=(i==n-1?1:h[i+1]);
		ll cur;
		cur=min(h[i],pre);
		cur=max(cur,min(h[i],nxt));
		ncnt+=h[i]-cur;
		h[i]=cur;
	//	cout<<i<<" "<<cur<<" "<<pre<<" "<<nxt<<" "<<h[i]<<endl;
		if(h[i]==1)
		{
	//		cout<<i<<endl;
			if(stp<edp)
				dive.pb(mp(stp,edp));
			stp=i+1,edp=i;
			ncnt++;
		}
		else edp++;
	}
	if(stp<edp)dive.pb(mp(stp,edp));
	ll ans=1;
	ans%=mod;
	rep(i,dive.size())
	{
		ans*=2*cal(dive[i].st,dive[i].nd);
		ans%=mod;
	}
//	cout<<ans<<endl;
//	cout<<ans<<endl;
	if(!dive.size())ans=1;
	if(ncnt)ans*=qp(2,ncnt);
	ans%=mod;
	printf("%lld\n",ans);
	return 0;
}