#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<(y);++i)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define print(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define print(x)
#endif

const int inf=1e9;
const int64_t inf64=1e18;
const double eps=1e-9;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
    os << "[";
    for (const auto &v : vec) {
    	os << v << ",";
    }
    os << "]";
    return os;
}

class union_find{
	private:
	vector<int> parent,rank,gs;
    int size;
	public:
    int count_group;
    union_find()=default;
    union_find(int n){ init(n); }
    void init(int n){
		size=n;
		count_group=n;
		parent.resize(size);
		rank.assign(size,0);
        gs.assign(size,1);
		for(int i=0; i<size; ++i) parent[i]=i;
	}
	int find(int x){
		if(parent[x]==x) return x;
		else return parent[x]=find(parent[x]);
	}
	void unite(int x,int y){
		x=find(x);
		y=find(y);
		if(x==y) return;
		if(rank[x]<rank[y]){
			parent[x]=y;
            gs[y]+=gs[x];
		} else {
			parent[y]=x;
            gs[x]+=gs[y];
			if(rank[x]==rank[y]) ++rank[x];
		}
		--count_group;
	}
	bool is_same_group(int x,int y){
		return find(x)==find(y);
	}
    int group_size(int x){
        return gs[find(x)];
    };
};

struct edge{
    int from,to,cost;
    bool operator<(const edge& other)const{
        return cost<other.cost;
    }
};

void solve(){
    int n,m;
    cin >> n >> m;
    vector<edge> edges;
    rep(i,0,m){
        int a,b,c;
        cin >> a >> b >> c;
        --a;
        --b;
        edges.push_back(edge({a,b,c}));
    }
    sort(edges.begin(),edges.end());

    union_find uf(n);
    vector<bool> use(m);
    int64_t sum_cost=0;
    rep(i,0,m){
        edge &e=edges[i];
        if(uf.is_same_group(e.to,e.from)) continue;
        uf.unite(e.to,e.from);
        sum_cost+=e.cost;
        use[i]=true;
    }

    vector<vector<pair<int,int>>> graph(n);
    rep(i,0,m){
        if(!use[i]) continue;
        graph[edges[i].from].push_back(make_pair(edges[i].to,edges[i].cost));
        graph[edges[i].to].push_back(make_pair(edges[i].from,edges[i].cost));
    }

    vector<vector<int>> max_cost(n,vector<int>(n));
    vector<bool> done(n);
    function<void(int,int,int)> dfs=[&](int s,int u,int ma){
        done[u]=true;
        max_cost[s][u]=ma;
        for(auto &p:graph[u]){
            if(done[p.first]) continue;
            dfs(s,p.first,max(ma,p.second));
        }
        done[u]=false;
    };
    rep(i,0,n) dfs(i,i,0);

    int q;
    cin >> q;
    rep(i,0,q){
        int s,t;
        cin >> s >> t;
        --s;
        --t;
        cout << sum_cost-max_cost[s][t] << endl;
    }
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    solve();
    return 0;
}
