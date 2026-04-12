// IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << ends << H; debug_out(T...); }
#define debug(...) cerr << "{" << #__VA_ARGS__ << "}:", debug_out(__VA_ARGS__)
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

////////////////////////////////////////////////////////////////////

const int N = 2e5 + 5;

int n, L[N], R[N], A[N];
ll SEG[N << 2], LAZY[N << 2], DP[N]; 
vector<int> QL[N], QR[N];

void Apply(int id, ll x) { SEG[id] += x, LAZY[id] += x; }
void Shift(int id) {
	if (LAZY[id] == 0) return;
	Apply(id << 1, LAZY[id]);
	Apply(id << 1 | 1, LAZY[id]);
	LAZY[id] = 0;
}
void Update(int l, int r, ll x, int id = 1, int s = 0, int e = n + 1) {
	if (l >= e || s >= r) { return; }
	if (l <= s && e <= r) { Apply(id, x); return; }
	Shift(id);
	int md = (s + e) >> 1;
	Update(l, r, x, id << 1, s, md);
	Update(l, r, x, id << 1 | 1, md, e);
	SEG[id] = max(SEG[id << 1], SEG[id << 1 | 1]);
}
ll Get(int l, int r, int id = 1, int s = 0, int e = n + 1) {
	if (l >= e || s >= r) return 0;
	if (l <= s && e <= r) return SEG[id];
	Shift(id);
	int md = (s + e) >> 1;
	return max(Get(l, r, id << 1, s, md), Get(l, r, id << 1 | 1, md, e));
}

int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int m; cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> L[i] >> R[i] >> A[i], QL[L[i]].push_back(i), QR[R[i]].push_back(i);
	ll open = 0;
	for (int i = 1; i <= n; i++) {
		for (int j : QL[i]) open += A[j];
		DP[i] = open + Get(0, i);
		Update(i, i + 1, DP[i] - open);
		for (int j : QR[i]) Update(L[j], i + 1, A[j]), open -= A[j];
	}
	ll mx = 0;
	for (int i = 1; i <= n; i++) mx = max(mx, DP[i]);
	cout << mx << endl;

	return 0;
}
