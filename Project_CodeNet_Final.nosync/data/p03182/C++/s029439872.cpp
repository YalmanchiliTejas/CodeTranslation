#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,m;
vector<P1>query[200005];
class segtree
{
public:
	#define s (1<<18)
	ll seg[s*2];
	ll lazy[s*2];
	void lazy_evaluate(int k)
	{
		if(k*2+2>=s*2) return ;
		lazy[k*2+2]+=lazy[k];
		lazy[k*2+1]+=lazy[k];
		seg[k*2+2]+=lazy[k];
		seg[k*2+1]+=lazy[k];
		lazy[k]=0;
	}
	ll update(int beg,int end,int idx,int lb,int ub,ll num)
	{
		if(ub<beg||end<lb)
		{
			return seg[idx];
		}
		if(beg<=lb&&ub<=end)
		{
			lazy[idx]+=num;
			seg[idx]+=num;
			return seg[idx];
		}
		if(lazy[idx])
		{
			lazy_evaluate(idx);
		}
		return seg[idx]=max(update(beg,end,idx*2+1,lb,(lb+ub)/2,num),update(beg,end,idx*2+2,(lb+ub)/2+1,ub,num));
	}
	ll query(int beg,int end,int idx,int lb,int ub)
	{
		if(ub<beg||end<lb)
		{
			return -1000000000000000000LL;
		}
		if(beg<=lb&&ub<=end)
		{
			return seg[idx];
		}
		if(lazy[idx])
		{
			lazy_evaluate(idx);
		}
		return max(query(beg,end,idx*2+1,lb,(lb+ub)/2),query(beg,end,idx*2+2,(lb+ub)/2+1,ub));
	}
}kaede;
//Kaede Takagaki is my wife!
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int L,R,a; scanf("%d%d%d",&L,&R,&a);
		query[L].pb(mp(1,mp(R,a)));
		query[R+1].pb(mp(-1,mp(L,a)));
	}
	ll ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<query[i].size();j++){
			int ty = query[i][j].fi;
			int za = query[i][j].sc.fi;
			int cs = query[i][j].sc.sc;
			if(ty == 1){
				kaede.update(0,i-1,0,0,s-1,1LL*cs);
			}
			else{
				kaede.update(0,za-1,0,0,s-1,-1LL*cs);
			}
		}
		ll v = kaede.query(0,i-1,0,0,s-1);
		ans = max(ans,v);
		kaede.update(i,i,0,0,s-1,v);
	}
	cout<<ans<<endl;
}
