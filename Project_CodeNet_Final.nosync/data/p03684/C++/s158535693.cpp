#include<bits/stdc++.h>
using namespace std;

const int mx=1e6+5;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;

int par[mx], rnk[mx];

void init(int n) {
	for (int i=0; i<n; i++)
		par[i]=i, rnk[i]=0;
}

int find(int x) {
	if(par[x]==x) return x;
	else return par[x]=find(par[x]);
}

void unite(int x, int y) {
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(rnk[x]<rnk[y]) par[x]=y;
	else {
		par[y]=x;
		if(rnk[x]==rnk[y]) rnk[x]++;
	}
}

bool same(int x, int y) {
	return find(x)==find(y);
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int N; cin>>N;
	vector<iii> v(N);
	for (int i=0; i<N; i++) {
		int x,y; cin>>x>>y;
		v[i]={{x,y},i+1};
	}
	vector<iii> edges;
	sort(v.begin(),v.end(),[&](const iii &a, const iii &b) {
		return a.first.first<b.first.first;
	});
	for (int i=1; i<N; i++) {
		int x=v[i].second, y=v[i-1].second, w=v[i].first.first-v[i-1].first.first;
		edges.push_back({{x,y},w});
	}
	sort(v.begin(),v.end(),[&](const iii &a, const iii &b) {
		return a.first.second<b.first.second;
	});
	for (int i=1; i<N; i++) {
		int x=v[i].second, y=v[i-1].second, w=v[i].first.second-v[i-1].first.second;
		edges.push_back({{x,y},w});
	}
	sort(edges.begin(),edges.end(),[&](const iii &a, const iii &b) {
		return a.second<b.second;
	});
	init(N+1);
	ll ret=0;
	for (auto e : edges) {
		int x=e.first.first, y=e.first.second, w=e.second;
		if(same(x,y)) continue;
		unite(x,y);
		ret+=w;
	}
	cout<<ret<<"\n";
	return 0;
}