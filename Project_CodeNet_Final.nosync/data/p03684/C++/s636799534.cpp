#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct UF{
	vector<int> par, rank;

	UF(int n){
		for(int i = 0; i < n; i++){
			par.emplace_back(i);
		}
		rank.assign(n, 0);
	}

	int root(int x){
		return par[x] == x ? x : par[x] = root(par[x]);
	}

	bool same(int x, int y){
		return root(x) == root(y);
	}

	void unite(int x, int y){
		x = root(x);
		y = root(y);
		if(rank[x] < rank[y]) par[x] = y;
		else{
			par[y] = x;
			if(rank[x] == rank[y]) rank[x]++;
		}
	}
};

int64_t dist(pair<int64_t, int64_t> a, pair<int64_t, int64_t> b){
	return min(abs(a.first - b.first), abs(a.second - b.second));
}

int main(){
	int n;
	cin >> n;
	pair<pair<int64_t, int64_t>, int> p[n];
	for(int i = 0; i < n; i++){
		cin >> p[i].first.first >> p[i].first.second;
		p[i].second = i;
	}
	pair<pair<int64_t, int64_t>, int> q[n];
	for(int i = 0; i < n; i++){
		q[i].first = {p[i].first.second, p[i].first.first};
		q[i].second = i;
	}
	sort(p, p + n);
	sort(q, q + n);
	priority_queue<pair<int64_t, pair<int, int>>, vector<pair<int64_t, pair<int, int>>>, greater<pair<int64_t, pair<int, int>>>> pq;	//cost, from, to
	for(int i = 0; i < n - 1; i++){
		pq.push(make_pair(dist(p[i].first, p[i + 1].first), make_pair(p[i].second, p[i + 1].second)));
		pq.push(make_pair(dist(q[i].first, q[i + 1].first), make_pair(q[i].second, q[i + 1].second)));
	}
	UF uf(n);
	int64_t ans = 0;
	while(!pq.empty()){
		auto puni = pq.top();
		pq.pop();
		int64_t d = puni.first;
		pair<int, int> ft = puni.second;
		if(!uf.same(ft.first, ft.second)){
			uf.unite(ft.first, ft.second);
			ans += d;
		}
	}
	cout << ans << endl;
}