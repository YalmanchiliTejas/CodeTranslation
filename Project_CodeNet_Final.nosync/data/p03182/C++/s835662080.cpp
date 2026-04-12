#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<long long, long long> pl;

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const double EPS = 1e-6;
const int MAX_N = 2e5 + 5;

class SegmentTree {
public:
	int N;
	vector<ll> minimum, delta;

	SegmentTree() {}

	SegmentTree(int N) {
		this->N = N;
		minimum = vector<ll>(4 * N + 1);
		delta = vector<ll>(4 * N + 1);
	}
	
	void update(int l, int r, ll val) {update(1, 0, N - 1, l, r, val);} //inclusive range
	
	ll query(int l, int r) {return query(1, 0, N - 1, l, r);} //inclusive range
	
	void push(int i) {
		delta[2 * i] += delta[i];
		delta[2 * i + 1] += delta[i];
		delta[i] = 0;
	}

	void pull(int i) {
		minimum[i] = min(minimum[2 * i] + delta[2 * i], minimum[2 * i + 1] + delta[2 * i + 1]);
	}
	
	void update(int i, int lo, int hi, int l, int r, ll val) {
		if (r < lo || hi < l) return;
		if (l <= lo && hi <= r) {
			delta[i] += val;
			return;
		}
		
		push(i);
		
		int m = (lo + hi) / 2;
		update(2 * i, lo, m, l, r, val);
		update(2 * i + 1, m + 1, hi, l, r, val);
		
		pull(i);
	}
	
	ll query(int i, int lo, int hi, int l, int r) {
		if (r < lo || hi < l) return (1 << 29);
		if (l <= lo && hi <= r) {
			return minimum[i] + delta[i];
		}
		
		push(i);
		
		int m = (lo + hi) / 2;
		ll minLeft = query(2 * i, lo, m, l, r);
		ll minRight = query(2 * i + 1, m + 1, hi, l, r);
		
		pull(i);
		
		return min(minLeft, minRight);
	}
};

int N, M;
vector<pi> intervals[MAX_N];
SegmentTree st(MAX_N);

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M;
	ll sum = 0;
	for (int i = 0; i < M; ++i) {
		int l, r, a; cin >> l >> r >> a;
		intervals[r].push_back({l, a});
		sum += a;
	}

	for (int i = 1; i <= N + 1; ++i) {
		for (pi seg: intervals[i - 1]) {
			st.update(0, seg.ff - 1, seg.ss);
		}
		st.update(i, i, st.query(0, i - 1));
	}

	cout << sum - st.query(0, N + 1) << '\n';

	return 0;
}