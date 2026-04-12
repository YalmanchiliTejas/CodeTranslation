#include <bits/stdc++.h>
typedef long long i64;
using std::cout;
using std::endl;
using std::cin;

struct PartialPersistentUnionFind {
	std::vector<std::vector<std::pair<int, int>>> history;
	std::vector<int> data, time;
	int now = 0;
	
	PartialPersistentUnionFind(int n) {
		history.assign(n, std::vector<std::pair<int, int>>(1, {0, -1}));
		time.assign(n, 1 << 30);
		data.assign(n, -1);
		now = 0;
	}
	
	int unite(int x, int y) {
		x = find(++now, x);
		y = find(now, y);
		if(x == y) return now;
		if(data[x] > data[y]) std::swap(x, y);
		data[x] += data[y];
		data[y] = x;
		history[x].push_back({now, data[x]});
		time[y] = now;
		return now;
	}
	
	int find(int t, int k) {
		if(time[k] > t) return k;
		return find(t, data[k]);
	}
	
	bool same(int t, int x, int y) {
		return find(t, x) == find(t, y);
	}
	
	int size(int t, int x) {
		x = find(t, x);
		return -std::prev(lower_bound(begin(history[x]), end(history[x]), std::make_pair(t, 0)))->second;
	}
};

int main(){
	int n, m; cin >> n >> m;
	std::vector<std::pair<int, std::pair<int, int>>> vec(m);
	for(int i = 0; i < m; i++) cin >> vec[i].second.first >> vec[i].second.second >> vec[i].first;
	sort(begin(vec), end(vec));
	
	int now = 1;
	i64 cost = 0;
	std::vector<int> pos;
	PartialPersistentUnionFind uf(n);
	for(int i = 0; i < m; i++) {
		i64 c = vec[i].first;
		auto p = vec[i].second;
		int x = p.first - 1, y = p.second - 1;
		
		if(uf.same(now, x, y)) continue;
		uf.unite(x, y); ++now;
		pos.push_back(c);
		cost += c;
	}
	
	int q; cin >> q;
	while(q--) {
		int x, y; cin >> x >> y; x--; y--;
		
		int ok = 0, ng = now;
		while(std::abs(ok - ng) > 1) {
			int mid = (ok + ng) / 2, sz = -1;
			
			if(!uf.same(mid, x, y)) ok = mid;
			else ng = mid;
		}
		
		cout << cost - pos[ok] << endl;
	}
	return 0;
}
