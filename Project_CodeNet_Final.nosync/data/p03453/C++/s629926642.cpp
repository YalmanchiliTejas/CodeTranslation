#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
#define ll long long 
#define pb push_back
//#define mp make_pair
#define fr first
#define sc second
#define N ((ll)(2e6+100))
#define MAX ((ll)(1e16+100))
#define ARRS ((ll)(3e5+100))
#define MOD ((ll)(1e9+7))
#define M1 ((ll)(1001783))
#define M2 ((ll)(1001941))
#define M3 ((ll)(1002073))
#define pb push_back
 
ll n,m,sr,ed;
struct va{
	ll fr,sc,i;
};
vector<va> v[ARRS];
set<pair<ll,ll> > st;
ll f[ARRS];
ll dp[ARRS];
vector<pair<ll,ll> > tp;
map<pair<ll,ll>,ll> mp;
map<pair<ll,ll>,ll> me;
ll k,p,c;

int main(){
 
	cin>>n>>m;
	cin>>sr>>ed;
	for(int i=0; i<m; i++){
		cin>>k>>p>>c;
		c=2*c;
		v[k].pb({p,c,i});
		v[p].pb({k,c,i});
	}
 
	for(int i=0; i<=n; i++)f[i]=-1;
	st.insert({0,sr});
	while(st.size()){
		auto p=*st.begin();
		st.erase(st.begin());
		ll x=p.sc;
		ll t=p.fr;
		if(f[x]!=-1)continue;
		f[x]=t;
		for(auto y:v[x])
			st.insert({t+y.sc,y.fr});
	}
 
	for(int i=1; i<=n; i++)
		tp.pb({f[i],i});
	sort(tp.begin(),tp.end());
	
	ll wh=f[ed]/2;
	dp[sr]=1;
	for(auto p:tp){
		auto x=p.sc;
		if(f[x]==wh){
			mp[{x,-1}]=dp[x];
			me[{x,-1}]+=f[x];
		}
		for(auto y:v[x]){
			if(f[y.fr]==f[x]+y.sc){
				dp[y.fr]=(dp[y.fr]+dp[x])%MOD;
				if(f[y.fr]>wh&&wh>f[x]){
					mp[{y.i,-2}]=dp[x];
					me[{y.i,-2}]+=f[x];
				}
			}
		}
	}
 
	swap(sr,ed);
	st.clear();
	tp.clear();
	memset(dp,0,sizeof(dp));
	for(int i=0; i<=n; i++)f[i]=-1;
 
 
	st.insert({0,sr});
	while(st.size()){
		auto p=*st.begin();
		st.erase(st.begin());
		ll x=p.sc;
		ll t=p.fr;
		if(f[x]!=-1)continue;
		f[x]=t;
		for(auto y:v[x])
			st.insert({t+y.sc,y.fr});
	}
 
	for(int i=1; i<=n; i++)
		tp.pb({f[i],i});
	sort(tp.begin(),tp.end());
	
	wh=f[ed]/2;
	dp[sr]=1;
	for(auto p:tp){
		auto x=p.sc;
		if(f[x]==wh){
			mp[{x,-1}]*=dp[x];
			me[{x,-1}]+=f[x];
		}
		for(auto y:v[x]){
			if(f[y.fr]==f[x]+y.sc){
				dp[y.fr]=(dp[y.fr]+dp[x])%MOD;
				if(f[y.fr]>wh&&wh>f[x]){
					mp[{y.i,-2}]*=dp[x];
					me[{y.i,-2}]+=f[y.fr];
				}
			}
		}
	}
	ll pas=0;
	ll s=0;
	for(auto x:mp){
		if(me[x.fr]!=f[ed])continue;
		x.sc%=MOD;
		pas=(pas+x.sc*s)%MOD;
		s=(s+x.sc)%MOD;
	}
	cout<<(pas*2ll)%MOD;
}
 
