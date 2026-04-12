#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
using lint = long long;
using pi = pair<int, int>;
const int mod = 1e9 + 7;

struct disj{
	int pa[MAXN];
	void init(int n){
		iota(pa, pa + n + 1, 0);
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q) return 0;
		pa[q] = p; return 1;
	}
}disj;

struct pnt{
	int x, y, idx;
}a[MAXN];

struct edg{
	int s, e, x;
};

int n;

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d %d",&a[i].x,&a[i].y);
		a[i].idx = i;
	}
	vector<edg> v;
	sort(a, a + n, [&](const pnt &a, const pnt &b){
		return pi(a.x, a.y) < pi(b.x, b.y);
	});
	for(int i=1; i<n; i++) v.push_back({a[i-1].idx, a[i].idx, a[i].x - a[i-1].x});
	for(int i=0; i<n; i++) swap(a[i].x, a[i].y);
	sort(a, a + n, [&](const pnt &a, const pnt &b){
		return pi(a.x, a.y) < pi(b.x, b.y);
	});
	for(int i=1; i<n; i++) v.push_back({a[i-1].idx, a[i].idx, a[i].x - a[i-1].x});
	sort(v.begin(), v.end(), [&](const edg &a, const edg &b){
		return a.x < b.x;
	});
	lint ret = 0;
	disj.init(n);
	for(auto &i : v){
		if(disj.uni(i.s, i.e)) ret += i.x;
	}
	cout << ret << endl;
}
