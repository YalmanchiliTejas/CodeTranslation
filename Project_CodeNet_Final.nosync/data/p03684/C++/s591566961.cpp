#include<bits/stdc++.h>
const int N = 1e5+5;
using namespace std;
int n;
struct Node{
	int x;
	int y;
	int id;
	void show(){
		cout << this->x <<" "<<this->y<<" "<<this->id<<"\n";
	}
}a[N];
bool cmp1(const Node &a, const Node &b){
	if(a.x < b.x) return 1;
	if(a.x == b.x) return a.y < b.y;
	return 0;
}
bool cmp2(const Node &a, const Node &b){
	if(a.y < b.y) return 1;
	if(a.x == b.x) return a.x < b.x;
	return 0;
}
struct cmpp{
	bool operator()(const Node &a, const Node &b){
		if(a.x > b.x) return 1;
		if(a.x == b.x) return a.y > b.y;
		return 0;
	}
};
priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>> > pq;

int counting;
vector<int> par, children;

void Start(int n){
	counting = n;
 	par.assign(n+1,-1);
	children.assign(n+1,1);
	for(int i = 1; i <= n; ++i){
		par[i] = i;
	}
	return;
}

int Find(int i){
	if(par[i] != i) par[i] = Find(par[i]);
	return par[i];
}

bool Union(int i, int j){
	i = Find(i);
	j = Find(j);
	if(i != j){
		if(children[i] < children[j]){
			par[i] = j;
			children[j] += children[i];	
		}else{
			par[j] = i;
			children[i] += children[j];
		}
		counting--;
	}else return 0;
	return 1;
}

signed main(){
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i].x >> a[i].y;
		a[i].id = i; 
		
	}
	
	sort(a+1, a+1+n, cmp1);
	for(int i = 1; i <= n; ++i){
		if(i!=1) pq.push(make_tuple(abs(a[i].x - a[i-1].x), a[i].id, a[i-1].id));
	}

	sort(a+1, a+1+n, cmp2);
	for(int i = 1; i <= n; ++i){
		if(i!=1) pq.push(make_tuple(abs(a[i].y - a[i-1].y), a[i].id, a[i-1].id));
	}
	int ans = 0, dist, u, v;
	Start(n);
	while(pq.size()){
		if(counting == 1) break;
		tie(dist, u, v) = pq.top();
		pq.pop();
		if(Union(u, v)){ 
			ans += dist;
		}
	}
	cout << ans <<"\n";
}
