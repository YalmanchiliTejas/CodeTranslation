#include <bits/stdc++.h>
using namespace std;

int n;
int m;

int l[200055], r[200055], a[200055];

vector<int> in[200055];
vector<int> out[200055];

long long dp[200055];

long long dat[800055];
long long lazy[800055];

void push(int from, int to) {
	dat[to] += lazy[from];
	lazy[to] += lazy[from];
}
void update(int id, int x, int y, int l, int r, long long val) {
	if (l > y || r < x) return;
	
	if (l <= x && y <= r) {
		dat[id] += val;
		lazy[id] += val;
		return;
	}
	
	int mid = (x + y) >> 1;
	
	if (lazy[id] != 0) {
		push(id, id + id);
		push(id, id + id + 1);
		
		lazy[id] = 0;
	}
	
	update(id + id, x, mid, l, r, val);
	update(id + id + 1, mid + 1, y, l, r, val);
	
	dat[id] = max(dat[id + id], dat[id + id + 1]);
}
long long query(int id, int x, int y, int l, int r) {
	if (l > y || r < x) return -LLONG_MAX;
	
	if (l <= x && y <= r) {
		return dat[id];
	}
	
	int mid = (x + y) >> 1;
	
	if (lazy[id] != 0) {
		push(id, id + id);
		push(id, id + id + 1);
		
		lazy[id] = 0;
	}
	
	return max(query(id + id, x, mid, l, r), query(id + id + 1, mid + 1, y, l, r));
}
int main() {
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &l[i], &r[i], &a[i]);
		
		in[l[i]].push_back(i);
		out[r[i]].push_back(i);
	}
	
	for (int i = 1; i <= n; i++) {
		for (auto v : in[i]) {
			update(1, 0, n, 0, i - 1, a[v]);
		}
		
		long long val = query(1, 0, n, 0, i - 1);
		
		dp[i] = val;
		
		update(1, 0, n, i, i, dp[i]);
		
		for (auto v : out[i]) {
			update(1, 0, n, 0, l[v] - 1, -a[v]);
		}
	}
	
	cout << *max_element(dp, dp + n + 1);
}
