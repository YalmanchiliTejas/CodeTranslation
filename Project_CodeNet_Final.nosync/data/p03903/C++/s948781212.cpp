#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
 
#define mod 1000000007
#define FOR(x,to) for(int x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define long long long
inline int rei(){int x;cin>>x;return x;}
inline long rel(){long x;cin>>x;return x;}
inline string res(){string x;cin>>x;return x;}
//------------------------------------------------------- 
template<class T>
struct SparseTable{
	vector<T> st[21];
	void Init(int N,vector<T> &data){
		if(N<=0)
			return;
		int h = 1;
		while ((1 << h) < N) h++;
		for(int i=0;i<N;i++) st[0].push_back(data[i]);
		for(int j=1;j<=h;j++){
			for(int i=0;i<N-(1<<j)+1;i++){
				st[j].push_back(min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]));
			}
		}
	}
	inline int TopBit(int t){
		return 31-__builtin_clz(t);
	}
	T GetMin(int b,int e){
		int diff = TopBit(e-b);
		return min(st[diff][b], st[diff][e - (1 << diff)]);
	}
};
struct LowestCommonAncestor{
    int N;
    vector<int> path, depth, in_order, out_order;
    std::vector<pair<int,int>> dat;
	SparseTable<pair<int,int>> table;

    LowestCommonAncestor(const vector<vector<int>> &G,int root)
        : N(G.size()),
          path(N * 2 - 1),
          depth(N * 2 - 1),
          in_order(N),
          out_order(N) {
        int k = 0;
        dfs(G, root, -1, 0, k);
        for (int i = 0; i < (int)depth.size(); ++i){
            dat.push_back(make_pair(depth[i],i));
		}
		table.Init(dat.size(),dat);
    }

    int Querry(int u,int v) {
        int l = min(in_order[u], in_order[v]);
        int r = max(in_order[u], in_order[v]) + 1;
        auto res = table.GetMin(l,r);
        return path[res.second];
    }

    void dfs(const vector<vector<int>> &G,int v,int f,int d,int &k) {
        in_order[v] = k;
        path[k] = v;
        depth[k++] = d;
        for (auto &e : G[v]){
            if (e != f) {
                dfs(G,e,v,d+1,k);
                path[k] = v;
                depth[k++] = d;
            }
        }
        out_order[v] = k-1;
    }
};
struct UnionFind{
    vector<int> par;
    UnionFind(int N){
        par.resize(N);
        for(int i=0;i<N;i++){
            par[i] = i;
        }
    }
    void Union(int x,int y){
        par[Get(x)] = Get(y); 
    }
    bool Same(int x,int y){
        return Get(x) == Get(y);
    }
    int Get(int x){
        if(x != par[x]){
            par[x] = Get(par[x]);
        }
        return par[x];
    }
};
pair<long,pair<int,int>> Edge[400000];
long cost[3999];
int leader[4000];
void Calc(){
	int N = rei();
	int M = rei();
	for(int i=0;i<M;i++){
		int f = rei()-1;
		int t = rei()-1;
		Edge[i] = {rel(),{f,t}};
	}
	for(int i=0;i<N;i++){
		leader[i] = i+N-1;
	}
	sort(Edge,Edge+M);
	vector<vector<int>> G(2*N-1);
	UnionFind U(N);
	int c = N-2;
	long ans = 0;
	for(int i=0;i<M;i++){
		int f = Edge[i].second.first;
		int t = Edge[i].second.second;
		if(!U.Same(f,t)){
			cost[c] = Edge[i].first;
			ans += Edge[i].first;
			G[c].push_back(leader[U.Get(f)]);
			G[c].push_back(leader[U.Get(t)]);
			U.Union(f,t);
			leader[U.Get(f)] = c--;
		}
	}
	LowestCommonAncestor LCA(G,0);
	int Q = rei();
	for(int i=0;i<Q;i++){
		int s = rei()-1;
		int t = rei()-1;
		cout << ans - cost[LCA.Querry(s+N-1,t+N-1)] << endl;;
	}

}
int main(int argc,char** argv){
	ios::sync_with_stdio(false), cin.tie(0);
	cout.tie(0); Calc(); return 0;
}