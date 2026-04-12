#include <bits/stdc++.h>
using namespace std;
const int maxn = 200200;
int x[maxn], y[maxn], q[maxn], cnt;
void add(int x){
	q[x]++;
	if(q[x] == 1) cnt++;
}
void rem(int x){
	q[x]--;
	if(q[x] == 0) cnt--;
}
int main(){
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	vector<pair<int, int> > vals;
	for(int i = 1; i <= n; i++){
		vals.push_back({x[i], -i});
		vals.push_back({y[i], +i});
	}
	sort(vals.begin(), vals.end());
	int mn = vals[0].first, mx = vals.back().first;
	long long ans = 1ll * (mx - mn) * (mx - mn);
	vector<int> g1, g2;
	for(int i = 1; i <= n; i++){
		if(x[i] > y[i]) swap(x[i], y[i]);
		g1.push_back(x[i]);
		g2.push_back(y[i]);
	}
	sort(g1.begin(), g1.end());
	sort(g2.begin(), g2.end());
	ans = min(ans, 1ll * (g1.back() - g1[0]) * (g2.back() - g2[0]));
	for(int i = 0, j = 0; i < 2 * n; i++){
		while(j < 2 * n && cnt < n){
			int id = vals[j].second;
			if(id < 0) id = -id;
			add(id);
			j++;
		}
		if(cnt == n){
			ans = min(ans, 1ll * (mx - mn) * (vals[j - 1].first - vals[i].first));
		}
		int id = vals[i].second;
		if(id < 0) id = -id;
		rem(id);
	}
	cout << ans << endl;
	return 0;
}

