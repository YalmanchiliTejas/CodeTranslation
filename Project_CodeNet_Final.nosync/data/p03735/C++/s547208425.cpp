#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n;
vector<pair<ll,ll>>vec;
vector<ll>za;
ll ans;
ll mnx=1e18,mxx=-1e18,mny=1e18,mxy=-1e18;
struct RMQ{
	#define s (1<<19)
	ll seg[s];
	void init(){ fill(seg,seg+s,-1e18); }
	void update(int k,ll a){
		k+=s/2-1; seg[k]=a;
		while(k>0){
			k=(k-1)/2;
			seg[k]=max(seg[k*2+1],seg[k*2+2]);
		}
	}
	ll query(int a,int b,int k,int l,int r){
		if(r<a || b<l) return -1e18;
		if(a<=l && r<=b) return seg[k];
		else{
			ll vl=query(a,b,k*2+1,l,(l+r)/2);
			ll vr=query(a,b,k*2+2,(l+r)/2+1,r);
			return max(vl,vr);
		}
	}
}kaede[2][2];
int main(){
	scanf("%d",&n);
	repn(i,n){
	    ll x,y;
		scanf("%lld%lld",&x,&y);
		if(x > y) swap(x,y);
		vec.pb(mp(x,y));
		za.pb(x); za.pb(y);
		mnx = min(mnx,x); mxx = max(mxx,x);
		mny = min(mny,y); mxy = max(mxy,y);
	}
	ans = (mxx-mnx) * (mxy-mny);
	rep(a,2)rep(b,2) kaede[a][b].init();
	sort(vec.begin(),vec.end());
	rep(i,vec.size()){
		kaede[0][0].update(i,vec[i].fi);
		kaede[0][1].update(i,-vec[i].fi);
		kaede[1][0].update(i,vec[i].sc);
		kaede[1][1].update(i,-vec[i].sc);
	}
	SORT(za); ERASE(za);
	int id = POSL(za,mny);
	
	for(int i=0;i<za.size();i++){
		int pos = POSL(vec,mp(za[i],-1ll));
		//[0,pos) -> max
		//[pos,n) -> min
		ll MX = kaede[1][0].query(0,pos-1,0,0,s/2-1);
		MX = max(MX,kaede[0][0].query(pos,n-1,0,0,s/2-1));
		ll MN = kaede[1][1].query(0,pos-1,0,0,s/2-1);
		MN = max(MN,kaede[0][1].query(pos,n-1,0,0,s/2-1));
		ll val = MX+MN;
		//cout << mxy << " " << mnx << endl;
		ans = min(ans, (mxy-mnx) * val);
	}
	cout << ans << '\n';
}
