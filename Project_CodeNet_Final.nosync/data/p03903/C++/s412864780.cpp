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


class lca_solver{
	public:
    vector<vector<int>> children;
    int root;
    // if root,parent is -1.
    vector<int> parent;
    vector<int> depth;
    vector<vector<int>> parent_pow2;
    lca_solver(vector<vector<int>> &children_,int root_)
        : children(children_),root(root_){
        calc_parent_and_depth();
        calc_parent_pow2();
    };
    int lca(int u,int v){
        // make sure depth(u) > depth(v).
        if(depth[u] < depth[v]) swap(u,v);
        for(size_t k=0;k<parent_pow2.size();k++){
            if(((depth[u] - depth[v]) >> k) & 1){
                u = parent_pow2[k][u];
            }
        }
        if(u == v) return u;
        for(int k=(int)parent_pow2.size()-1;k>=0;k--){
            if(parent_pow2[k][u] != parent_pow2[k][v]){
                u = parent_pow2[k][u];
                v = parent_pow2[k][v];
            }
        }
        return parent_pow2[0][u];
    }
	private:
    void calc_parent_and_depth(){
        parent = vector<int>(children.size(),-1);
        depth = vector<int>(children.size(),-1);
        sub_calc_parent_and_depth(root,-1,0);
    }
    void sub_calc_parent_and_depth(int cur,int par,int dep){
        parent[cur] = par;
        depth[cur] = dep;
        for(int child : children[cur]){
            if(child != par){
                sub_calc_parent_and_depth(child,cur,dep+1);
            }
        }
    }
    void calc_parent_pow2(){
        // parent_pow2[k][i] = 2^k parent of node i.
        parent_pow2 = vector<vector<int>>(ceil(log(children.size())/log(2)+1),
                                          vector<int>(children.size(),-1));
        parent_pow2[0] = parent;
        for(size_t k=0;k+1<parent_pow2.size();k++){
            for(size_t v=0;v<children.size();v++){
                if(parent_pow2[k][v] >= 0){
                    parent_pow2[k+1][v] = parent_pow2[k][parent_pow2[k][v]];
                }
            }
        }
    }
};

template<class T> class segtree{
public:
    int n,size_;
    vector<T> dat;
    function<T(T,T)> fun_;
    T id_;
    segtree()=default;
    segtree(int size,function<T(T,T)> fun,T id,T initial_value){ init(size,fun,id,initial_value); }
    void init(int size,function<T(T,T)> fun,T id,T initial_value){
        size_=size;
        fun_=fun;
        id_=id;
        n=1;
        while(n<size) n*=2;
        dat.assign(2*n-1,id);
        for(int i=0; i<size; ++i) update(i,initial_value);
    }
    int size()const{ return size_; }
    void update(int k, T a) {
        k+=n-1; // leaf
        dat[k]=a;
        while(k>0) {
            k=(k-1)/2;
            dat[k]=fun_(dat[k*2+1],dat[k*2+2]);
        }
    }
    T at(int index){ return dat[index+n-1]; }
    void add(int k,T a){ update(k,at(k)+a); }
    T query(int a,int b) { return query(a,b,0,0,n); }
    T query(int a,int b,int k,int l,int r) {
        if(r<=a or b<=l) return id_;
        if(a<=l and r<=b) return dat[k];
        int m=(l+r)/2;
        return fun_(query(a,b,k*2+1,l,m),query(a,b,k*2+2,m,r));
    }
};

void solve(){
    int n,m;
    cin >> n >> m;
    vector<edge> edges;
    vector<unordered_map<int,int>> cost(n);
    rep(i,0,m){
        int a,b,c;
        cin >> a >> b >> c;
        --a;
        --b;
        edges.push_back(edge({a,b,c}));
        cost[a][b]=cost[b][a]=c;
    }
    sort(edges.begin(),edges.end());
    union_find uf(n);
    int64_t sum_cost=0;
    vector<vector<int>> mst(n);
    rep(i,0,m){
        edge &e=edges[i];
        if(uf.is_same_group(e.to,e.from)) continue;
        uf.unite(e.to,e.from);
        sum_cost+=e.cost;
        mst[e.from].push_back(e.to);
        mst[e.to].push_back(e.from);
    }

    int root=0;
    vector<vector<int>> children(n);
    function<void(int,int)> dfs=[&](int u,int p){
        for(int v:mst[u]){
            if(v==p) continue;
            children[u].push_back(v);
            dfs(v,u);
        }
    };
    dfs(root,-1);
    lca_solver ls(children,root);

    vector<vector<int>> max_cost(20,vector<int>(n));
    rep(i,0,n){
        if(i==root) continue;
        int j=ls.parent_pow2[0][i];
        max_cost[0][i]=cost[i][j];
    }
    rep(i,1,20){
        rep(j,0,n){
            if(ls.depth[j]-(1<<i)<0) continue;
            max_cost[i][j]=max(max_cost[i-1][j],max_cost[i-1][ls.parent_pow2[i-1][j]]);
        }
    }

    auto f=[&](int u,int v){
        int res=0;
        //rep(i,0,20){
        for(int i=19; i>=0; --i){
            if(ls.depth[u]-ls.depth[v]>=(1<<i)){
                res=max(res,max_cost[i][u]);
                u=ls.parent_pow2[i][u];
            }
        }
        return res;
    };

    int q;
    cin >> q;
    rep(i,0,q){
        int s,t;
        cin >> s >> t;
        --s;
        --t;
        int u=ls.lca(s,t);
        cout << sum_cost-max(f(s,u),f(t,u)) << endl;
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
