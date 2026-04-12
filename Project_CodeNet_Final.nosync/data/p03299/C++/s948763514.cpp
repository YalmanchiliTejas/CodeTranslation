#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void add(int &x,int y) {
	x += y; if (x >= mod) x -= mod;
}

int mul(int x,int y) {
	return (long long) x * y % mod;
}

int pw(int x,int y) {
	int ret = 1;
	while (y) {
		if (y & 1) ret = mul(ret, x);
		x = mul(x, x);
		y >>= 1;
	}
	return ret;
}

pair<int,int> solve(vector<int> h) {
	int n = h.size();
	int mn = mod, cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (mn > h[i]) {
			mn = h[i], cnt = 0;
		}
		cnt += (h[i] == mn);
	}
	
	int l = 0, r = 0;
	vector<pair<int,int>> vec; 
	while (l < n) {
		vector<int> new_h;
		while (l < n && h[l] == mn) l++;
		r = l;
		while (r < n && h[r] > mn) r++;
		for (int i = l; i < r; ++i) new_h.push_back(h[i] - mn);
		if (new_h.size()) vec.push_back(solve(new_h));
		l = r;	
	}
	pair<int,int> ret;
	ret.first = pw(2, mn);
	for (auto p : vec) ret.first = mul(ret.first, p.first);
	ret.second = pw(2, cnt);
	for (auto p : vec) ret.second = mul(ret.second, p.first + p.second);
	int coef = pw(2, mn); add(coef, mod - 2);
	for (auto p : vec) coef = mul(coef, p.first);
	add(ret.second, coef);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; ++i) cin >> h[i];
	cout << solve(h).second << '\n';
}
