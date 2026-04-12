#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
using namespace std;
const int maxn = 200100;
ll tree[4*maxn];
ll lazy[4*maxn];

ll n, m;
vector<pll>intervals[maxn];
ll dp[maxn];

void push_update(int li, int ri, int index) {
	if(lazy[index] != 0) {
		tree[index] += lazy[index];

		if(li != ri) {
			lazy[2*index] += lazy[index];
			lazy[2*index+1] += lazy[index];
		}

		lazy[index] = 0;
	}
}

void update(int ul, int ur, ll val, int li=0, int ri=n+1, int index=1) {
	push_update(li, ri, index);
	if(li > ur || ri < ul) return;
	else if(li >= ul && ri <= ur) {
		lazy[index] += val;
		push_update(li, ri, index);
	}
	else {
		int mid = (li + ri) / 2;

		update(ul, ur, val, li, mid, 2*index);
		update(ul, ur, val, mid+1, ri, 2*index+1);

		tree[index] = min(tree[2*index], tree[2*index+1]);
	}
}

ll query(int ql, int qr, int li=0, int ri=n+1, int index=1) {
	push_update(li, ri, index);
	if(li > qr || ri < ql) return 0LL;
	else if(li >= ql && ri <= qr) return tree[index];
	else {
		int mid = (li + ri) / 2;

		ll lq = query(ql, qr, li, mid, 2*index);
		ll rq = query(ql, qr, mid+1, ri, 2*index+1);

		tree[index] = min(tree[2*index], tree[2*index+1]);

		return min(lq, rq);
	}
}

int main() {
	cin>>n>>m;
	ll a, b, c;
	ll score = 0LL;
	for(int i=0;i<m;i++) {
		cin>>a>>b>>c;
		intervals[b].pb({a, c});
		score += c;
	}

	ll result = LLONG_MAX;
	for(int i=1;i<=n+1;i++) {
		for(pll p:intervals[i-1]) {
			update(0, p.first-1, p.second);
		}

		dp[i] = query(0, i-1);
		update(i, i, dp[i]);

		if(dp[i] < result) result = dp[i];
	}
	cout<<score-result<<"\n";
}