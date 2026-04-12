#include <bits/stdc++.h>
#include <alloca.h>
using namespace std;
#define int long long
vector<int> g[100010];
vector<int> tr[100010];
set< pair<int,int> > *altEdges[100010];
int a[200010],b[200010],w[200010],to[200010];
int uf[200010];
int used[200010];
int res[200010];

vector<int> es;


int root(int x){ return x == uf[x] ? x : uf[x] = root(uf[x]); }
int unite(int x,int y){ x = root(x); y = root(y); uf[x] = y; }
int minCost = 0;

int merge(int x,int y){
	if( altEdges[x]->size() < altEdges[y]->size() ){
		swap(altEdges[x],altEdges[y]);
	}
	unite(x,y);
	for( auto c : *altEdges[y] ){
		int eid = c.second;
		if( root(a[eid]) == root(b[eid]) ){
			altEdges[x]->erase({w[eid],eid});
		}else{
			altEdges[x]->insert({w[eid],eid});
		}
	}
}

vector< pair<int,int> > tour;
int gen(int src){
	stack< pair<int,int> > S;
	S.push({src,-1});
	while( S.size() ){
		src = S.top().first;
		int eid = S.top().second;
		S.pop();
		tour.push_back({src,eid});
		for( auto e : tr[src] ){
			if( e != eid ){
				int dst = src^to[e];
				S.push({dst,e});
			}
		}
	}
}
int dfs(int src,int eid){
	for(int i = 0 ; i < tour.size() ; i++){
		src = tour[i].first;
		eid = tour[i].second;
		for( auto e : g[src] ){
			if( e != eid ){
				altEdges[src]->insert({w[e],e});
			}
		}
		for( auto e : tr[src] ){
			if( e != eid ){
				int dst = src^to[e];
				merge(src,dst);
			}
		}
		if( eid != -1 ){
			while( altEdges[src]->size() ){
				int e2 = altEdges[src]->begin()->second;
				if( root(a[e2]) != root(b[e2]) ) break;
				altEdges[src]->erase({w[e2],e2});
			}
			if( altEdges[src]->size() ){
				res[eid] = minCost - w[eid] + altEdges[src]->begin()->first;
			}else{
				res[eid] = -1;
			}
		}
	}
}


signed main(){
	int n,m;
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++)
		altEdges[i] = new set< pair<int,int> >();
	es.resize(m);
	for(int i = 0 ; i < m ; i++){
		cin >> a[i] >> b[i] >> w[i];
		--a[i],--b[i];
		to[i] = a[i] ^ b[i];
		g[a[i]].push_back(i);
		g[b[i]].push_back(i);
		es[i] = i;
	}
	for(int i = 0 ; i < n ; i++) uf[i] = i;
	sort(es.begin(),es.end(),[](int x,int y){return w[x]<w[y];});
	for(auto i : es ){
		if( root(a[i]) != root(b[i]) ){
			unite(a[i],b[i]);
			minCost += w[i];
			used[i] = true;
			tr[a[i]].push_back(i);
			tr[b[i]].push_back(i);
		}
	}
	for(int i = 0 ; i < m ; i++) res[i] = minCost;
	for(int i = 0 ; i < n ; i++) uf[i] = i;
	gen(0);
	reverse(tour.begin(),tour.end());
	dfs(0,-1);
	for(int i = 0 ; i < n ; i++){
		if( root(0) != root(i) ){
			for(int j = 0 ; j < m ; j++) res[j] = -1;
			break;
		}
	}
	for(int i = 0 ; i < m ; i++) cout << res[i] << endl;
	

}