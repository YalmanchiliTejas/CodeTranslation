
	#include <bits/stdc++.h>
	using namespace std;
	#include <ext/pb_ds/assoc_container.hpp> 
	#include <ext/pb_ds/tree_policy.hpp> 
	using namespace __gnu_pbds; 
	#define ordered_set tree<int,int_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
	#define ordered_set_pair tree<pair<int,int>,int_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update> 
	 
	typedef long long int ll;
	typedef long double ld;
	typedef unsigned long long int ull;
	typedef pair<int,int> pi; 
	#define PI 3.1415926535897932384
	#define FOR(i,vv,n) for(int i=vv;i<n;i++)
	#define FORR(i,n,vv) for(int i=n-1;i>=vv;i--)
	#define ve vector 
	#define maxind(v) (max_element(v.begin(),v.end())-v.begin())
	#define minind(v) (min_element(v.begin(),v.end())-v.begin())
	#define maxe(v) *max_element(v.begin(),v.end())
	#define mine(v) *min_element(v.begin(),v.end())
	#define pb push_back
	#define pf push_front
	#define ppb pop_back
	#define ppf pop_front
	#define eb emplace_back
	#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#define mp make_pair
	#define M 1000000007ll
	#define M1 100000000000000000ll
	#define PRECISE cout.precision(18);
	#define BS(v,n) binary_search(v.begin(),v.end(),n)
	#define srt(v) sort(v.begin(),v.end())
	#define rsrt(v) sort(v.begin(),v.end(),greater <int>())
	#define F first
	#define S second
	#define GET(i,p) get<i>(p)


	ve <ll> parent(100000);
	void make_set(){
		FOR(i,0,100000)
		parent[i]=i;
	}
	ll find_set(ll u){
	if(u==parent[u])
	return u;
	else return parent[u]=find_set(parent[u]);
	}
	void combine(ll u,ll v){
		ll a1=find_set(u);
		ll a2=find_set(v);
		parent[a1]=a2;
	}



	int main(){

	    FAST
	//	PRECISE

	make_set();
	ll n;
	cin>>n;
	ve <pair<pair<ll,ll>,ll>> v[2];
	FOR(i,0,n){
		ll x,y;
		cin>>x>>y;
		v[0].pb({{x,y},i});
		v[1].pb({{y,x},i});
	}
	ve <tuple<ll,ll,ll> > edges;
	srt(v[1]);srt(v[0]);
	FOR(j,0,2)
	FOR(i,1,v[j].size()){

		edges.pb(make_tuple(v[j][i].F.F-v[j][i-1].F.F,v[j][i].S,v[j][i-1].S));
	}
	srt(edges);
	ll ans=0;
	FOR(i,0,edges.size()){
	ll d1=GET(0,edges[i]);
	ll a1=GET(1,edges[i]);
	ll a2=GET(2,edges[i]);

	if(find_set(a1)!=find_set(a2)){
		ans+=d1;
		combine(a1,a2);
	}



	}

	cout<<ans;






	//cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	return 0;
	 }