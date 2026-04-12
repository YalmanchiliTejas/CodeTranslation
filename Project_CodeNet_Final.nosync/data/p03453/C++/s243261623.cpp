//teja349
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*100+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false); 
ll dist[123456],paths[123456],dist1[123456],paths1[123456];
vector<vl> adj(123456),wt(123456);  
ll n,iinf;
ll dijkstra(ll s){
	ll i;
	set<pll> seti;
	set<pll>::iterator it;
	rep(i,n){
    	dist[i]=iinf;
    	paths[i]=0;
    	seti.insert(mp(dist[i],i));
    }
    seti.erase(mp(dist[s],s));
    dist[s]=0;
    paths[s]=1;
    seti.insert(mp(dist[s],s));
    pll papa;
    ll u;
    while(!seti.empty()){
    	it=seti.begin();
    	papa=*it;
    	seti.erase(it);
    	u=papa.ss;
    	//cout<<u<<" "<<dist[u]<<endl;
    	rep(i,adj[u].size()){
    		if(dist[adj[u][i]]>dist[u]+wt[u][i]){
    			seti.erase(mp(dist[adj[u][i]],adj[u][i]));
    			dist[adj[u][i]]=dist[u]+wt[u][i];
    			seti.insert(mp(dist[adj[u][i]],adj[u][i]));
    		}
    		if(dist[adj[u][i]]+wt[u][i]==dist[u]){
    			paths[u]+=paths[adj[u][i]];
    			paths[u]%=mod;	
    		}
    	}
    }
    //exit(0);
    return 0;
    
}
int main(){
    std::ios::sync_with_stdio(false);
    ll m;
    iinf =inf;
    iinf*=inf;
    cin>>n>>m;
    ll s,t;
    cin>>s>>t;
    s--;
    t--;
    ll i,u,v,d,j,p;
    rep(i,m){
    	cin>>u>>v>>d;
    	//edge.pb(mp(d,mp(u,v)));
    	u--;
    	v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    	wt[u].pb(d);
    	wt[v].pb(d);
    }
    
    dijkstra(s);
    rep(i,n){
    	paths1[i]=paths[i];
    	dist1[i]=dist[i];
    	paths[i]=0;
    	//cout<<i<<" "<<paths1[i]<<endl;
    }
    dijkstra(t);
    ll ans=paths[s]*paths[s];
    ans%=mod;
    //cout<<ans<<endl;
    ll foo=dist[s],val;
    rep(i,n){	
    	if(dist[i]+dist1[i]==foo && dist[i]*2==foo){
    		val=paths[i]*paths1[i];
    		val%=mod;
			val*=val;
			val%=mod;
			ans-=val;
    		ans%=mod;
    	}
    }
    rep(i,n){
    	rep(p,adj[i].size()){
    		j=adj[i][p];
    		if(dist1[i]+dist[j]+wt[i][p]==foo){
    			if(dist1[i]*2<foo && dist1[j]*2>foo){
    				val=paths1[i]*paths[j];
    				val%=mod;
    				val*=val;
    				val%=mod;
    				ans-=val;
    				ans%=mod;
    			}
    		}
    	}
    }
    ans+=mod;
    ans%=mod;
    cout<<ans<<endl;

    return 0;  
    
}

