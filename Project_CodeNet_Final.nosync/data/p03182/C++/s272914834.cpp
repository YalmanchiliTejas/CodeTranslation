#include <bits/stdc++.h>

using namespace std;

template<class T, class U>
void ckmin(T &a, U b)
{
	if (a > b) a = b;
}
template<class T, class U>
void ckmax(T &a, U b)
{
	if (a < b) a = b;
}

#define MP make_pair
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define FORD(i, a, b) for (auto i = (a) - 1; i >= (b); i--)
#define SZ(x) ((int) ((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define INF 1000000007
#define LLINF 2696969696969696969ll
#define MAXN 200013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N, M;
vpl pts[MAXN];
ll dp[MAXN];
ll seg[3 * MAXN], lazy[3 * MAXN];
ll ans;

void push(int w, int L, int R)
{
	if (lazy[w] == 0) return;
	seg[w] += lazy[w];
	if (L != R)
	{
		lazy[w << 1] += lazy[w];
		lazy[w << 1 | 1] += lazy[w];
	}
	lazy[w] = 0;
}
void update(int w, int L, int R, int a, int b, ll v)
{
	push(w, L, R);
	if (b < L || R < a) return;
	if (a <= L && R <= b)
	{
		lazy[w] += v;
		push(w, L, R);
		return;
	}
	int mid = (L + R) >> 1;
	update(w << 1, L, mid, a, b, v);
	update(w << 1 | 1, mid + 1, R, a, b, v);
	seg[w] = max(seg[w << 1], seg[w << 1 | 1]);
	return;
}
ll query(int w, int L, int R, int a, int b)
{
	push(w, L, R);
	if (b < L || R < a) return -LLINF;
	if (a <= L && R <= b)
	{
		return seg[w];
	}
	int mid = (L + R) >> 1;
	return max(query(w << 1, L, mid, a, b), query(w << 1 | 1, mid + 1, R, a, b));
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	FOR(i, 0, M)
	{
		int l, r; ll v;
		cin >> l >> r >> v; l--; r--;
		pts[r].PB({l, -v});
		dp[0] += v;
	}
	//(x, v) means you pay v if x...cur are all 0s
	//dp[x] = best cost, given that x - 1 is a 1:
	// cerr << dp[0] << endl;
	update(1, 0, N + 1, 0, 0, dp[0]);
	// cerr << "UPDATE " << 0 << ' ' << 0 << ' ' << dp[0] << endl;
	FOR(i, 1, N + 2)
	{
		dp[i] = query(1, 0, N + 1, 0, i - 1);
		update(1, 0, N + 1, i, i, dp[i]);
		for (pll p : pts[i - 1])
		{
			int x = p.fi; ll v = p.se;
			// cerr << "UPDATE " << 0 << ' ' << x << ' ' << v << endl;
			update(1, 0, N + 1, 0, x, v);
		}
		// cerr << "QUERY " << 0 << ' ' << i - 1 << ' ' << dp[i] << endl;
		// cerr << "UPDATE " << i << ' ' << i << ' ' << dp[i] << endl;
	}
	FOR(i, 0, N + 2)
	{
		ckmax(ans, dp[i]);
		// cerr << dp[i] << ' ';
	}
	// cerr << endl;
	cout << ans << '\n';
	return 0;
}
