#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <cstring>
#include <queue>
#include <assert.h>
#include <cmath>
using namespace std;
using ll = long long;
const int mxn = 200010;
const ll inf = 1e18L+5;
ll dp[mxn], t[2*mxn], lazy[2*mxn];
int N, tree_size;

void apply(int p, ll val) {
	t[p]+=val;
	if(p<tree_size) lazy[p]+=val;
}

void build(int p) {
	while(p>1) p/=2, t[p] = min(t[2*p], t[2*p+1])+lazy[p];
}

void push(int p) {
	int h = floor(log2(tree_size));
	for(int s=h; s>0; --s) {
		int i = p>>s;
		assert(i);
		if(lazy[i]!=0) {
			apply(2*i, lazy[i]);
			apply(2*i+1, lazy[i]);
			lazy[i] = 0;
		}
	}
}

void inc(int l , int r, ll val) {
	//cout << "inc\n";
	l+=tree_size, r+=tree_size;
	int l0 = l, r0 = r;
	for(; l<=r; l/=2, r/=2) {
		if(l&1) apply(l, val);
		if(!(r&1)) apply(r, val);
		l++, r--;
	}
	build(l0);
	build(r0);
}

ll get_min(int l, int r) {
	//cout << "get_min\n";
	l+=tree_size, r+=tree_size;
	push(l);
	push(r);
	ll ret = inf;
	for(; l<=r; l/=2, r/=2) {
		if(l&1) ret = min(ret, t[l]);
		if(!(r&1)) ret =min(ret, t[r]);
		l++, r--;
	}
	assert(ret!=inf);
	return ret;
}

vector<pair<int, int> > intervals[mxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>N;
	int M; cin>>M;

	ll sum = 0;
	while(M--) {
		int l, r, val;
		cin>>l>>r>>val;
		intervals[r].emplace_back(l, val);
		sum = sum+(ll) val;
	}
	tree_size = N+1;
	dp[0] = 0; inc(0, 0, 0);
	dp[1] = 0; inc(1, 1, 0);

	for(int i=2; i<=N+1; i++) {
		for(auto x:intervals[i-1]) {
			int l = x.first, val = x.second;
			inc(0, l-1, (ll) val);
		}
		dp[i] = get_min(0, i-1);
		inc(i, i, dp[i]);
	}

	cout << sum-dp[N+1] << '\n';
	return 0;
}