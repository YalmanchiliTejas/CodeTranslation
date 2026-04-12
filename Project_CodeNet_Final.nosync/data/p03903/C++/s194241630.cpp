#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef pair<int,pii> edge;

const int N = 4005;
int uf[N];

int id(int v) {
	if(uf[v] == v) return v;
	return uf[v] = id(uf[v]);
}

void merge(int u, int v) {
	uf[id(u)] = id(v);
}

vector<edge> v;

vvi T;
vvi W;
int d[4005][4005],n,m,q;

void find(int f, int s, int t, int ds) {
	d[s][t] = ds;
	for(int i = 0; i < T[t].size(); ++i) {
		int v = T[t][i];
		if(v == f) continue;
		find(t,s,v,max(W[t][i],ds));
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie();
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		uf[i] = i;
	for(int i = 0;i < m; ++i) {
		int a,b,c;
		cin >> a >> b >> c;
		v.push_back(edge(c,pii(a-1,b-1)));
	}
	sort(v.begin(),v.end());
	ll wt = 0;
	T = vvi(n,vi());
	W = vvi(n,vi());
	for(int i = 0; i < v.size(); ++i) {
		int a = v[i].second.first,b=v[i].second.second;
		if(id(a) == id(b))
			continue;
		merge(a,b);
		wt += v[i].first;
		T[a].push_back(b);
		T[b].push_back(a);
		W[a].push_back(v[i].first);
		W[b].push_back(v[i].first);
	}
	for(int i = 0; i < n; ++i)
		find(-1,i,i,0);
	cin >> q;
	while(q--) {
		int s,t;
		cin >> s >> t;
		--s; --t;
		cout << wt - d[s][t] << "\n";
	}

	return 0;
}