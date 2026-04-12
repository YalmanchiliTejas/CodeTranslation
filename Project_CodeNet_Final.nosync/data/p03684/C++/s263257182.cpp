#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define spair(p) cout<<#p<<": "<<p.fi<<" "<<p.se<<endl
#define sar(a,n) cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl
#define svec(v) cout<<#v<<":";rep(pachico,v.size())cout<<" "<<v[pachico];cout<<endl
#define svecp(v) cout<<#v<<":";each(pachico,v)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl
#define sset(s) cout<<#s<<":";each(pachico,s)cout<<" "<<pachico;cout<<endl
#define smap(m) cout<<#m<<":";each(pachico,m)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl

using namespace std;

typedef pair<int,int> P;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<P> vp;
typedef vector<string> vs;

const int MAX_N = 100005;

class UF {
private:
    int sz; vector<int> par,nrank;
public:
    UF(){}
    UF(int node_size){ sz = node_size; par.resize(sz),nrank.resize(sz); rep(i,sz){ par[i] = i; nrank[i] = 0; } }
    int find(int x){ if(par[x] == x){ return x; }else{ return par[x] = find(par[x]); } }
    void unite(int x,int y)
    { x = find(x),y = find(y); if(x == y) return;
    	if(nrank[x] < nrank[y]){ par[x] = y; }else{ par[y] = x; if(nrank[x] == nrank[y]) nrank[x]++; } }
    bool same(int x,int y){ return find(x) == find(y); }
};

template<typename T> class Kruskal{
public:
	struct edge{
		int u,v;
		T cost;
		bool operator<(const edge& another) const {
			return cost < another.cost;
		}
	};
	vector<edge> es;
	int V;
    Kruskal(int node_size) : V(node_size){}
	void add_edge(int u,int v,T cost){
		es.push_back((edge){u,v,cost});
	}
	T solve(){
		UF uf(V);
		T res = 0;
		int cnt = 0;
        sort(es.begin(),es.end());
		rep(i,(int)es.size()){
			edge e = es[i];
			if(!uf.same(e.u,e.v)){
				uf.unite(e.u,e.v);
				res += e.cost;
				cnt++;
				if(cnt == V-1){
					break;
				}
			}
		}
		return res;
	}
};

typedef pair<P,int>pi;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
	Kruskal<ll> kr(n);
	vector<pi> u(n),v(n);
	rep(i,n){
		int x,y;
		cin >> x >> y;
		u[i] = pi(P(x,y),i);
		v[i] = pi(P(y,x),i);
	}
	sort(all(u)), sort(all(v));
	rep(i,n-1){
		kr.add_edge(u[i].se,u[i+1].se,min(abs(u[i].fi.fi-u[i+1].fi.fi),abs(u[i].fi.se-u[i+1].fi.se)));
		kr.add_edge(v[i].se,v[i+1].se,min(abs(v[i].fi.fi-v[i+1].fi.fi),abs(v[i].fi.se-v[i+1].fi.se)));
	}
	cout << kr.solve() << "\n";
    return 0;
}
