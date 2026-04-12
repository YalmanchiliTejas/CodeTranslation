#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
struct point {
	int x,y;
}arr[maxn];
struct edge {
	int u,v,cost;
};
int pa[maxn];
int Find(int x) {
	return pa[x] == x ? x : pa[x] = Find(pa[x]);
}
void Union(int x,int y) {
	pa[Find(x)] = Find(y);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> arr[i].x >> arr[i].y;
	vector<int> idxs(n);
	iota(idxs.begin(),idxs.end(),1);
	vector<edge> E;
	
	sort(idxs.begin(),idxs.end(),[=](int a,int b)->bool
		{return arr[a].x < arr[b].x;});
	for(int i=1;i<n;i++) {
		int u = idxs[i-1] , v = idxs[i];
		E.push_back(edge{u,v,arr[v].x - arr[u].x});
	}
	sort(idxs.begin(),idxs.end(),[=](int a,int b)->bool
		{return arr[a].y < arr[b].y;});
	for(int i=1;i<n;i++) {
		int u = idxs[i-1] , v = idxs[i];
		E.push_back(edge{u,v,arr[v].y - arr[u].y});
	}
	
	sort(E.begin(),E.end(),[=](edge a,edge b)->bool
		{return a.cost < b.cost;});
	iota(pa+1,pa+1+n,1);
	int ans = 0;
	for(edge e : E) {
		int u = e.u , v = e.v , cost = e.cost;
		if(Find(u) != Find(v))
			ans += cost , Union(u,v);
	}
	cout << ans << endl;
	return 0;
}
