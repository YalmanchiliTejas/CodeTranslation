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

using i64=int64_t;

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

void solve(){
    i64 N;
    cin >> N;
    vector<i64> x(N),y(N);
    vector<pair<i64,i64>> xi,yi;
    rep(i,0,N){
        cin >> x[i] >> y[i];
        xi.push_back(make_pair(x[i],i));
        yi.push_back(make_pair(y[i],i));
    }
    sort(xi.begin(),xi.end());
    sort(yi.begin(),yi.end());

    vector<pair<i64,i64>> dx,dy;
    rep(i,0,N-1){
        dx.push_back(make_pair(xi[i+1].first-xi[i].first,i));
        dy.push_back(make_pair(yi[i+1].first-yi[i].first,i));       
    }
    sort(dx.begin(),dx.end());
    sort(dy.begin(),dy.end());

    i64 ans=0;
    union_find uf(N);
    i64 i=0,j=0;
    while(uf.count_group>1){
        if(i<N-1 and (j==N-1 or dx[i].first<dy[j].first)){
            i64 u=xi[dx[i].second].second,v=xi[dx[i].second+1].second;
            if(uf.is_same_group(u,v)){
                ++i;
                continue;
            }
            uf.unite(u,v);
            ans+=min(abs(x[u]-x[v]),abs(y[u]-y[v]));
        }else{
            i64 u=yi[dy[j].second].second,v=yi[dy[j].second+1].second;
            if(uf.is_same_group(u,v)){
                ++j;
                continue;
            }
            uf.unite(u,v);
            ans+=min(abs(x[u]-x[v]),abs(y[u]-y[v]));
        }
    }
    cout << ans << endl;
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    solve();
    return 0;
}
