#include<bits/stdc++.h>

using namespace std;

using Weight=long long;

struct Edge{
    int src,dst;
    Weight weight;
    Edge(int src,int dst,Weight weight):
    src(src),dst(dst),weight(weight){}
};

auto operator < (const Edge &e,const Edge &f){
    if(e.weight!=f.weight)return e.weight>f.weight;
    else if(e.src!=f.src)return e.src<f.src;
    else return e.dst<f.dst;
}

using Edges=vector<Edge>;
using Graph=vector<Edges>;

template<typename T>
struct UnionFind{
    vector<T>data;
    UnionFind(T n):data(n,-1){}
    bool unite(T x,T y){
        x=root(x);y=root(y);
        if(x!=y){
            if(data[y]<data[x])swap(x,y);
            data[x]+=data[y];data[y]=x;
        }
        return x!=y;
    }
    T root(T x){
        return data[x]<0?x:data[x]=root(data[x]);
    }
    bool same(T x,T y){
        return root(x)==root(y);
    }
    T size(T x){
        return -data[root(x)];
    }
};

pair<Weight,Edges>kruskal(const Graph &g){
    int n=g.size();
    UnionFind<int> uf(n);
    priority_queue<Edge>q;
    for(int i=0;i<n;++i){
        for(auto e:g[i]){
            if(i<e.dst)q.push(e);
        }
    }
    Weight total=0;
    Edges forest;
    while(forest.size()<n-1 && !q.empty()){
        Edge e=q.top();q.pop();
        if(uf.unite(e.src,e.dst)){
            forest.push_back(e);
            total+=e.weight;
        }
    }
    return pair<Weight, Edges>(total,forest);
}

int main(){
	int n;
	cin>>n;
	vector<pair<Weight,int>>px(n),py(n);
	for(int i=0;i<n;++i){
		int x,y;
		cin>>x>>y;
		px[i]=make_pair(x,i);
		py[i]=make_pair(y,i);
	}
	sort(px.begin(),px.end());
	sort(py.begin(),py.end());
	Graph g(n);
	for(int i=0;i<n-1;++i){
		g[px[i].second].emplace_back(px[i].second,px[i+1].second,px[i+1].first-px[i].first);
		g[px[i+1].second].emplace_back(px[i+1].second,px[i].second,px[i+1].first-px[i].first);
		g[py[i].second].emplace_back(py[i].second,py[i+1].second,py[i+1].first-py[i].first);
		g[py[i+1].second].emplace_back(py[i+1].second,py[i].second,py[i+1].first-py[i].first);
	}
	cout<<kruskal(g).first<<endl;
}
