#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;

int n,x,y,par[N];
struct dot{
	int x,y,id;
	bool operator < (dot other) const{
		return x < other.x;
	}
};
vector<dot> vx,vy;
struct edge{
	int u,v,w;
	bool operator < (edge other) const{
		return w < other.w;
	}
};
vector<edge> e;

int find(int p){
	if (p==par[p]){
		return p;
	}
	return par[p]=find(par[p]);
}

void merge(int p, int q){
	p=find(p);
	q=find(q);
	par[p]=q;
}

bool cmp(dot p, dot q){
	return p.y < q.y;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> x >> y;
		vx.push_back({x,y,i});
		vy.push_back({x,y,i});
	}
	sort(vx.begin(),vx.end());
	sort(vy.begin(),vy.end(),cmp);
	for (int i=1;i<n;i++){
		e.push_back({vx[i].id,vx[i-1].id,
		vx[i].x-vx[i-1].x});
	}
	for (int i=1;i<n;i++){
		e.push_back({vy[i].id,vy[i-1].id,
		vy[i].y-vy[i-1].y});
	}
	sort(e.begin(),e.end());
	for (int i=1;i<=n;i++){
		par[i]=i;
	}
	long long ans=0;
	for (auto &now : e){
		if (find(now.u)!=find(now.v)){
			merge(now.u,now.v);
			ans+=now.w;
		}
	}
	cout << ans << "\n";
}