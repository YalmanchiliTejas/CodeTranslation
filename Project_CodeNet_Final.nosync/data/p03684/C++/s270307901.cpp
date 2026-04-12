#include <bits/stdc++.h>
using namespace std;

int n;
struct point{
	int x;
	int y;
	int idx;
} p[100004];

bool cmp1(point a, point b){
	return a.x<b.x;
}
bool cmp2(point a, point b){
	return a.y<b.y;
}
pair<int,pair<int,int>> e[200004];
int parent[100004], size[100004], r[100004]; 
void init(){ 
	for (int i=1; i<=n; i++) { 
		parent[i] = i; 
		size[i] = 1; 
		r[i] = 0; 
	} 
}

int find(int p){ 
	if(parent[p] == p) return p; 
	else return parent[p] = find(parent[p]); 
} 
void uni(int p, int q){ 
	p = find(p); 
	q = find(q); 
	if(r[p] < r[q]) parent[p] = q, size[q] += size[p]; 
	else parent[q] = p, size[p] += size[q]; 
	if(r[p] == r[q]) r[p]++; 
}


int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	for(int i = 1; i <= n;i++){
		cin>>p[i].x>>p[i].y;
		p[i].idx = i;
	}
	sort(p+1,p+n+1,cmp1);
	for(int i = 1;i<n;i++){
		e[i].first = abs(p[i].x-p[i+1].x);
		e[i].second = {p[i].idx,p[i+1].idx};
	}
	sort(p+1,p+n+1,cmp2);
	for(int i = 0;i<n-1;i++){
		e[i+n].first = abs(p[i+1].y-p[i+2].y);
		e[i+n].second = {p[i+1].idx,p[i+2].idx};
	}
	sort(e+1,e+2*n-1);
	init();
	long long ans = 0;
	for(int i = 1;i<=2*n-2;i++){
		int a = e[i].second.first;
		int b = e[i].second.second;
		if(find(a) == find(b))	continue;
		uni(a,b);
		ans += e[i].first;
	}
	cout<<ans;
	return 0;
}
