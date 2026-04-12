#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for(int i = (int) (l);i < (int) (r);i++)
template<typename T> bool chmax(T& a,const T& b){ return a < b ? (a = b,true) : false; }
template<typename T> bool chmin(T& a,const T& b){ return b < a ? (a = b,true) : false; }
typedef long long ll;

struct UnionFind{
	vector<int> par,rank;
	UnionFind(int n) :par(n + 1),rank(n + 1,1){
		for(int i = 1;i <= n;i++) par [i] = i;
	}
	int find(int x){
		return par [x] == x ? x : par [x] = find(par [x]);
	}
	bool unite(int x,int y){
		x = find(x);
		y = find(y);
		if(x == y) return false;
		if(rank [x] < rank [y]) swap(x,y);
		rank [x] += rank [x] == rank [y];
		par [y] = x;
		return true;
	}
	bool same(int x,int y){
		return find(x) == find(y);
	}
};

int N;
vector< pair<int,int> > X,Y;
struct edge{
	int a,b,len;
	bool operator<(const edge& other){
		return len < other.len;
	}
};
vector<edge> G;
const int INF = 2e9;

int main()
{
	scanf("%d",&N);
	X.assign(N,make_pair(0,0));
	Y.assign(N,make_pair(0,0));
	FOR(i,0,N){
		scanf("%d%d",&X [i].first,&Y [i].first);
		X [i].second = Y [i].second = i;
	}
	sort(X.begin(),X.end());
	sort(Y.begin(),Y.end());
	FOR(i,0,N - 1){
		G.push_back(edge{X [i].second,X [i + 1].second,X [i + 1].first - X [i].first});
		G.push_back(edge{Y [i].second,Y [i + 1].second,Y [i + 1].first - Y [i].first});
	}
	sort(G.begin(),G.end());

	UnionFind uf(N);
	ll ans = 0;
	int cnt = 1;
	for(int i = 0;i < G.size() && cnt < N;i++){
		if(uf.same(G [i].a,G [i].b) == false){
			uf.unite(G [i].a,G [i].b);
			ans += G [i].len;
			cnt++;
		}
	}

	printf("%lld\n",ans);

	return 0;
}
