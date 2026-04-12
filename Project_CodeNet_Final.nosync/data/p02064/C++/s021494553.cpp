#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int query(int u, int v){
	if(u == v){ return 0; }
	cout << "? " << u << " " << v << endl;
	int x;
	cin >> x;
	return x;
}

int main(){
	int n, s, t;
	cin >> n >> s >> t;
	vector<int> ds(n + 1), dt(n + 1);
	for(int i = 1; i <= n; ++i){
		ds[i] = query(s, i);
		dt[i] = query(i, t);
	}
	vector<pair<int,int>> cands;
	for(int i = 1; i <= n; ++i){
		if(i != s && ds[i] + dt[i] == ds[t]){
			cands.emplace_back(ds[i], i);
		}
	}
	sort(cands.begin(), cands.end());
	vector<int> ans;
	ans.push_back(s);
	for(auto c : cands){
		int u = ans.back();
		int v = c.second;
		int d = query(u, v);
		if(ds[u] + d == ds[v]){
			ans.push_back(v);
		}
	}
	cout << "!";
	for(int x : ans){
		cout << " " << x;
	}
	cout << endl;
}

