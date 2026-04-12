#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
 
#define rep(pos, len) for(int pos=0;pos<len;pos++)
#define repp(pos, len) for(int pos=1;pos<=len;pos++)
 
#define INF 87654321
#define IINF 87654321987654321
#define MOD 1000000007

typedef pair<int, long> Pil;

struct SegmentTree {
	int n;
	vector<ll> sum, mx;
	void init(int sz) {
		n = 1;
		while(n < sz) n <<= 1;
		sum.assign(2*n, 0);
		mx.assign(2*n, 0);
	}

	void add(int p, ll val) {
		if(p <= 0 || p > n) return;
		p += n-1;
		sum[p] += val;
		mx[p] = sum[p];
		for(p >>= 1; p; p >>= 1) {
			sum[p] = sum[2*p] + sum[2*p+1];
			mx[p] = max(mx[2*p], sum[2*p] + mx[2*p+1]);
		}
	}

	ll maxSum(int p) {
		if(p <= 0) return 0;
		vector<int> vi;
		for(p += n-1; p; p >>= 1) {
			if(!(p&1)) {
				vi.push_back(p);
				p--;
			}
		}
		reverse(vi.begin(), vi.end());
		ll curSum = 0, mxSum = 0;
		for(int i : vi) {
			mxSum = max(curSum + mx[i], mxSum);
			curSum += sum[i];
		}
		return mxSum;
	}
} tree;


const int MAXN = 2e5 + 50;
int l[MAXN], r[MAXN], n, m;
ll a[MAXN];
vector<Pil> adj[MAXN], rev[MAXN];
void readInput() {
	scanf("%d%d", &n, &m);
	repp(i, m) scanf("%d%d%lld", &l[i], &r[i], &a[i]);
	repp(i, m) {
		adj[l[i]].emplace_back(r[i], a[i]);
		rev[r[i]].emplace_back(l[i], a[i]);
	}
}

void solve() {
	tree.init(n);
	ll res = 0, cur = 0;
	for(int k = 1; k <= n; k++) {
		for(auto e : adj[k]) {
			cur += e.second;
			tree.add(k, -e.second);
			tree.add(e.first+1, e.second);
		}
		ll val = tree.maxSum(k-1) + cur;
		//printf("%d: %lld %lld\n", k, val, cur);
		res = max(res, val);
		tree.add(k, val);
		tree.add(k+1, -val);
		for(auto e : rev[k]) {
			cur -= e.second;
			tree.add(e.first, e.second);
			tree.add(k+1, -e.second);
		}
	}
	printf("%lld\n", res);
}


int main() {
	readInput();
	solve();
}