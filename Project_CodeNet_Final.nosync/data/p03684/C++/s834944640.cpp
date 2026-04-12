#include <bits/stdc++.h>
using namespace std;

struct union_find_tree {
    std::vector<int> par, rank;
    union_find_tree(){}
    union_find_tree(int size)
    {
        par=std::vector<int>(size);
        rank=std::vector<int>(size);
        for(int i=0; i<size; ++i) par[i]=i;
    }
    int root(int x)
    {
        if (x==par[x]) return x;
        return par[x]=root(par[x]);
    }
    void unite(int x, int y)
    {
        x=root(x);
        y=root(y);
        if (x==y) return;
        if (rank[x]<rank[y]) {
            par[x]=y;
        }
        else {
            par[y]=x;
            if (rank[x]==rank[y]) ++rank[x];
        }
    }
    bool same(int x, int y)
    {
        return root(x)==root(y);
    }
};


int main()
{
	int n; cin>>n;
	vector<tuple<int, int, int>> p;
	for(int i=0; i<n; ++i) {
		int x, y; cin>>x>>y;
		p.emplace_back(i, x, y);
	}

	vector<tuple<int, int, int>> edges;

	sort(begin(p), end(p), [](auto& a, auto& b){ return get<1>(a)<get<1>(b);});
	for(int i=0; i<n-1; ++i) {
		int a, x, y; tie(a, x, y)=p[i];
		int b, s, t; tie(b, s, t)=p[i+1];
		edges.emplace_back(min(abs(x-s), abs(y-t)), a, b);
	}
	sort(begin(p), end(p), [](auto& a, auto& b){ return get<2>(a)<get<2>(b);});
	for(int i=0; i<n-1; ++i) {
		int a, x, y; tie(a, x, y)=p[i];
		int b, s, t; tie(b, s, t)=p[i+1];
		edges.emplace_back(min(abs(x-s), abs(y-t)), a, b);
	}
 
	sort(begin(edges), end(edges));
	union_find_tree uf(n);
	long res=0;
	for(auto& e: edges) {
		int c, u, v; tie(c, u, v)=e;
		if (uf.same(u, v)) continue;
		uf.unite(u, v);
		res+=c;
	}
	cout<<res<<endl;
}