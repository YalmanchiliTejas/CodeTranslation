#include <bits/stdc++.h>
#define REP(a, b) for(int a = 0; a < b; a++)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define mp make_pair
#define f first
#define s second
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> LL;
typedef vector<int> vi;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;
const int MAXN = 2e5 + 100;

int n, m;
ll st[4 * MAXN];
ll lazy[4 * MAXN];
ll DP[MAXN];
set<LL> unik;
pair<ii, ll> A[MAXN];

void turunkan(int p, int l, int r) {
	st[p] = st[p] + lazy[p];
	if (l == r) {
		lazy[p] = 0;
		return;
	}
	lazy[p << 1] += lazy[p];
	lazy[p << 1 | 1]  += lazy[p];
	lazy[p] = 0;
}

void update(int p, int l, int r, int x, int y, ll val) {
	turunkan(p, l, r);
	if (l > y || r < x) return;
	if (l >= x && r <= y) {
		lazy[p] = val;
		turunkan(p, l, r);
		return;
	}
	int mid = (l + r) >> 1;
	update(p << 1, l, mid, x, y, val);
	update(p << 1 | 1, mid + 1, r, x, y, val);
	st[p] = max(st[p << 1], st[p << 1 | 1]);
}

ll query(int p, int l, int r, int x, int y) {
	turunkan(p, l, r);
	if (l > y || r < x) return -INF;
	if (l >= x && r <= y) {
		//cout << p << ' ' << l << ' ' << r << ' ' << x << ' ' << y << ' ' << st[p] << '\n';
		return st[p];
	}
	int mid = (l + r) >> 1;
	return max(query(p << 1, l, mid, x, y), query(p << 1 | 1, mid + 1, r, x, y)); 
}

ll maksi = 0;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	REP(i, m) cin >> A[i].f.f >> A[i].f.s >> A[i].s;
	sort(A, A + m);
	int sek = 0;
	REP(i, n + 1) {
		if (i == 0) continue;
		while (sek < m && A[sek].f.f == i) {
			//cout << i << ' ' << A[sek].f.f << ' ' << A[sek].f.s << ' ' << A[sek].s << " EA\n";
			unik.insert(mp(A[sek].f.s, sek));
			update(1, 0, n, 0, A[sek].f.f - 1, A[sek].s);
			sek++;
		}
		//cout << i - 1 << '\n';
		DP[i] = query(1, 0, n, 0, i - 1);
		//cout << i << ' ' << DP[i] << '\n';
		maksi = max(maksi, DP[i]);
		update(1, 0, n, i, i, DP[i]);
		while(true) {
			if (unik.empty()) break;
			LL now = *(unik.begin());
			if (now.f == i) {
				unik.erase(unik.begin());
				//cout << i << ' ' << A[now.s].f.f << ' ' << A[now.s].f.s << ' ' << A[now.s].s << " eAA\n";
				update(1, 0, n, 0, A[now.s].f.f - 1, -A[now.s].s);
			}
			else break;
		}
	}
	cout << maksi << '\n';
}