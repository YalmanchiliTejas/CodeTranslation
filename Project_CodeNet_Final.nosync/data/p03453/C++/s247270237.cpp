#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ll long long
#define mp make_pair
using namespace std;
vector< pair<ll,ll> > tc[114514];
ll dps[114514], dpt[114514], dis[114514];
int main(){
	ll n,m,s,t;
	cin>>n>>m>>s>>t;
	for(int i=0;i<m;i++){
		ll u,v,d;
		cin>>u>>v>>d;
		tc[u].pb( mp(d,v) );
		tc[v].pb( mp(d,u) );
	}
	priority_queue< pair<ll,ll> > que;
	que.push(mp(0,s));
	for(int i=1;i<=n;i++){
		dis[i] = (ll)mod * (ll)mod;
	}
	dis[s]=0;
	while(!que.empty()){
		ll cdis = -que.top().first;
		ll cpos = que.top().second;
		que.pop();
		if(dis[cpos]<cdis){continue;}
		for(int i=0;i<tc[cpos].size();i++){
			ll cdes = tc[cpos][i].second;
			ll ddis = tc[cpos][i].first;
			ll ncost = cdis + ddis;
			if(ncost < dis[cdes]){
				dis[cdes]=ncost;
				que.push(mp(-ncost, cdes));
			}
		}
	}
	vector< pair<ll,ll> > dispos;
	for(int i=1;i<=n;i++){
		dispos.pb( mp( dis[i], i) );
	}
	sort(dispos.begin(),dispos.end());
	dps[s] = 1;
	for(int i=0;i<n;i++){
		ll cpos = dispos[i].second;
		ll cdis = dispos[i].first;
		for(int j=0;j<tc[cpos].size();j++){
			ll cdest = tc[cpos][j].second;
			ll ddis = tc[cpos][j].first;
			if( cdis + ddis == dis[cdest]){
				dps[cdest] += dps[cpos];
				dps[cdest] %= mod;
			}
		}
	}
	reverse(dispos.begin(),dispos.end());
	dpt[t] = 1;
	for(int i=0;i<n;i++){
		ll cpos = dispos[i].second;
		ll cdis = dispos[i].first;
		for(int j=0;j<tc[cpos].size();j++){
			ll cdest = tc[cpos][j].second;
			ll ddis = tc[cpos][j].first;
			if( cdis - ddis == dis[cdest]){
				dpt[cdest] += dpt[cpos];
				dpt[cdest] %= mod;
			}
		}
	}
	ll tim = dis[t];
	ll ans = (dps[t] * dps[t])%mod;
	for(int i=1;i<=n;i++){
		if(dis[i]*2 == tim){
			ll tmp = (dps[i]*dpt[i])%mod;
			//cout<<"vertex"<<i<<" "<<dps[i]<<" "<<dpt[i]<<" "<<tmp<<endl;
			tmp = (tmp*tmp)%mod;
			ans = (ans+mod-tmp)%mod;
		}
		for(int j=0;j<tc[i].size();j++){
			ll de = tc[i][j].second;
			ll di = tc[i][j].first;
			if(dis[i]*2<tim && dis[de]*2>tim && dis[de]-dis[i]==di){
				ll tmp = (dps[i]*dpt[de])%mod;
				//cout<<"edge"<<i<<"&"<<de<<" "<<dps[i]<<" "<<dpt[de]<<" "<<tmp<<endl;
				tmp = (tmp*tmp)%mod;
				ans = (ans+mod-tmp)%mod;
			}
		}
	}
	cout<<ans%mod<<endl;
	return 0;
}