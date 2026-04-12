#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<cstdio>
#include<sstream>
#include<iomanip>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int,pii> pip;
typedef vector<pip>vip;
const double PI=acos(-1);
const double EPS=1e-8;
const ll inf=1e17;
struct UnionFind{
    vector<ll> data;
    UnionFind(ll size) : data(size, -1) {}
    bool unionSet(ll x,ll y){
        x=root(x);y=root(y);
        if(x==y)return 0;
        if(data[y]<data[x])swap(x,y);
        data[x]+=data[y],data[y]=x;
        return 1;
    }
    bool findSet(ll x,ll y){
        return root(x)==root(y);
    }
    ll root(ll x){
        return data[x]<0 ? x : data[x]=root(data[x]);
    }
    ll size(ll x){
        return -data[root(x)];
    }
};
class KRK{//c++11
	public:
	struct edge{
		ll from,to,cost;
	};
	vector<edge>G;
	vvp tG;
	vvi dp;
	vi used;
	ll n;
	KRK(ll size){
		n=size;
	}
	void add_edge(ll a,ll b,ll c){
		edge e={a,b,c};
		G.pb(e);
	}
	ll krk(){
		ll sum=0;
		sort(all(G),[](edge a,edge b){
			return a.cost<b.cost;
		});
		UnionFind uf(n);
		rep(i,G.size()){
			edge e=G[i];
			if(!uf.findSet(e.from,e.to)){
				sum+=e.cost;
				tG[e.from].pb(pii(e.to,e.cost));
				tG[e.to].pb(pii(e.from,e.cost));
				uf.unionSet(e.from,e.to);
			}
		}
		return sum;
	}
	void dfs(ll a,ll b,ll c){
		rep(i,tG[a].size())if(used[tG[a][i].first]==0){
			used[tG[a][i].first]=true;
			ll t=max<ll>(b,tG[a][i].second);
			dp[c][tG[a][i].first]=t;
			dfs(tG[a][i].first,t,c);
		}
	}
	void solve(){
		tG=vvp(n);
		ll out=krk();
		dp=vvi(n,vi(n));
		rep(i,n){
			used=vi(n);
			used[i]=1;
			dfs(i,0,i);
		}
//		rep(i,n){rep(j,n)cout<<" "<<dp[i][j];cout<<endl;}
		
		ll q;
		cin>>q;
		while(q--){
			ll a,b;
			cin>>a>>b;
			a--;b--;
			cout<<out-dp[a][b]<<endl;
		}
	}
};
int main(){
	ll n,m;
	cin>>n>>m;
	KRK krk(n);
	while(m--){
		ll a,b,c;
		cin>>a>>b>>c;
		a--;b--;
		krk.add_edge(a,b,c);
	}
	krk.solve();
}







