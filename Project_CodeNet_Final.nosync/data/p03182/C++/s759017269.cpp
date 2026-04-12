//khodaya khodet komak kon
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#pragma GCC optimise ("ofast")
#pragma GCC optimise("unroll-loops")
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 200000 + 10;
const ll MOD = 1000000000 + 7;
const ll INF = 1000000000000000000;
const ll LOG = 20;

int n, m, l[N], r[N], a[N], ind[N], dp[N];
ll seg[N << 2], lazy[N << 2];
vi vl[N], vr[N];

void modify(int id, ll x){
	seg[id] += x;
	lazy[id] += x;
	return;
}

void shift(int id){
	modify(id << 1, lazy[id]);
	modify(id << 1 | 1, lazy[id]);
	lazy[id] = 0;
	return;
}

void add(int id, int lq, int rq, int x, int l, int r){
	if (rq <= l || r <= lq) return;
	if (lq <= l && r <= rq){
		modify(id, x);
		return;
	}
	shift(id);
	int mid = (l + r) >> 1;
	add(id << 1, lq, rq, x, l, mid);
	add(id << 1 | 1, lq, rq, x, mid, r);
	seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
	return;
}

ll get(int id, int lq, int rq, int l, int r){
	if (rq <= l || r <= lq) return 0;
	if (lq <= l && r <= rq){
		return seg[id];
	}	
	shift(id);
	int mid = (l + r) >> 1;
	return max(get(id << 1, lq, rq, l, mid), get(id << 1 | 1, lq, rq, mid, r));
}

void calc(){
	for (int i = 1; i <= m + 1; i++){
		vl[l[i]].pb(i);
		vr[r[i]].pb(i);
	}
	ll sum = 0;
	for (int i = 1; i < N; i++){
		for (auto u:vl[i]){
			sum += a[u];
		}
		//if (i == 1) cout << sum << '\n';
		dp[i] = sum + get(1, 0, i, 0, N);
		//cout << i << ' ' << dp[i] << '\n';
		add(1, i, i + 1, dp[i] - sum, 0, N);
		for (auto u:vr[i]){
			add(1, l[u], r[u] + 1, a[u], 0, N);
			sum -= a[u];
		}
	}
	return;
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		cin >> l[i] >> r[i] >> a[i];
		ind[i] = i;
	}
	l[m + 1] = N - 1, r[m + 1] = N - 1, a[m + 1] = 0;
	calc();
	cout << dp[N - 1];









	return 0;
}
