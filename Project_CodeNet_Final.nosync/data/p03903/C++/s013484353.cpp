#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for(int i = (l);i < (r);i++)
#define ALL(x) (x).begin(),(x).end()
template<typename T> bool chmax(T& a,const T& b){return a < b ? (a = b,true) : false;}
template<typename T> bool chmin(T& a,const T& b){return b < a ? (a = b,true) : false;}
typedef long long ll;

class UnionFind{
	private:
		vector<int> parent;
		vector<int> rank;
	public:
		UnionFind(int n)
			:parent(n + 1),rank(n + 1,1){
			for(int i = 1;i <= n;i++) parent [i] = i;
		}
		int find(int x){
			if(parent [x] == x) return x;
			return parent [x] = find(parent [x]);
		}
		bool connect(int x,int y){
			x = find(x),y = find(y);
			if(x == y) return false;
			if(rank [x] < rank [y]) swap(x,y);
			if(rank [x] == rank [y]) rank [x]++;
			parent [y] = x;
			return true;
		}
		bool same(int x,int y){
			return find(x) == find(y);
		}
};

int N,M,Q;
list< pair<int,ll> > edge [4001],used_edge [4001];
struct st{
	int a,b;
	ll c;
	bool operator<(const st& other){
		return this->c < other.c;
	}
};
ll max_edge [4001] [4001];

ll dfs(int curr,int prev,int s,ll mx)
{
	max_edge [s] [curr] = mx;
	max_edge [curr] [s] = mx;
	for(auto&& it : used_edge [curr]) if(it.first != prev){
		dfs(it.first,curr,s,max(mx,it.second));
	}
}

int main()
{
	scanf("%d%d",&N,&M);
	vector<st> A(M);
	FOR(i,0,M){
		scanf("%d%d%lld",&A [i].a,&A [i].b,&A [i].c);
		edge [A [i].a].push_back({A [i].b,A [i].c});
		edge [A [i].b].push_back({A [i].a,A [i].c});
	}
	sort(ALL(A));

	scanf("%d",&Q);
	vector< pair<int,int> > query(Q);
	FOR(i,0,Q){
		scanf("%d%d",&query [i].first,&query [i].second);
	}

	ll ans = 0;
	UnionFind uf(N);
	FOR(i,0,M){
		if(uf.same(A [i].a,A [i].b) == false){
			uf.connect(A [i].a,A [i].b);
			used_edge [A [i].a].push_back({A [i].b,A [i].c});
			used_edge [A [i].b].push_back({A [i].a,A [i].c});
			ans += A [i].c;
		}
	}

	for(int i = 1;i <= N;i++){
		dfs(i,-1,i,0);
	}

	FOR(i,0,Q){
		printf("%lld\n",ans - max_edge [query [i].first] [query [i].second]);
	}

	return 0;
}
