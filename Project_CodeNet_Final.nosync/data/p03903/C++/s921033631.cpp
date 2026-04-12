#include<bits/stdc++.h>
using namespace std;
#define all(vec) vec.begin(),vec.end()
typedef long long int ll;
typedef pair<int,int> P;
const ll MOD=1000000007;
const ll INF=1000000010;
const ll LINF=4000000000000000010LL;
const int MAX=310;
const double EPS=1e-9;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
struct UnionFind{
    vector<int> par;
    vector<int> dep;
    
    UnionFind(int siz){
        par.assign(siz,0);
        dep.assign(siz,0);
        for(int i=0;i<siz;i++){
            par[i]=i;
        }
    };

    int find(int x){
        if(par[x]==x){
            return x;
        }else{
            return par[x]=find(par[x]);
        }
    }

    void unite(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y){
            return;
        }
        if(dep[x]<dep[y]){
            par[x]=y;
        }else{
            par[y]=x;
            if(dep[x]==dep[y]){
                dep[x]++;
            }
        }
    }

    bool same(int x,int y){
        return find(x)==find(y);
    }
};
struct edge{int from,to;ll cost;};

bool comp(const edge& e1,const edge& e2){
	return e1.cost<e2.cost;
}

struct edge2{int to;ll cost;};
vector<edge2> G[4010];

edge es[400010];
ll s[4010][4010];
void dfs(int now,int p,int st,ll ma){
	for(auto e:G[now]){
		if(e.to==p)continue;
		s[st][e.to]=max(ma,e.cost);
		dfs(e.to,now,st,max(ma,e.cost));
	}
}
	
int main(){
	int n,m,q;cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b,c;cin>>a>>b>>c;a--;b--;
		es[i]={a,b,c};
	}
	sort(es,es+m,comp);
	UnionFind uf(n+1);
	ll ans=0;
	for(int i=0;i<m;i++){
		edge e=es[i];
		if(!uf.same(e.from,e.to)){
			uf.unite(e.from,e.to);
			G[e.from].push_back({e.to,e.cost});
			G[e.to].push_back({e.from,e.cost});
			ans+=e.cost;
		}
	}
	for(int i=0;i<n;i++){
		dfs(i,-1,i,0);
	}
	cin>>q;
	while(q--){
		int a,b;cin>>a>>b;a--;b--;
		cout<<ans-s[a][b]<<endl;
	}
		
    return 0;
}
