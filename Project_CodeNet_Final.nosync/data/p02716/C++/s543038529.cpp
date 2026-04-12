#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define all(a) (a).begin(), (a).end()
#define x first
#define y second
#define lb(v, z) lower_bound(all(v), z)
#define ub(v, z) upper_bound(all(v), z)
#define fill(a, z) memset(a, z, sizeof(a))
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define rdp(i, a, b) for (int i = (a); i >= (b); i--)
#define rlt(i, a, b) for (int i = (a); i < (b); i++)
#define cns(z) cout << z << ' '
#define cnl(z) cout << z << '\n'
#define printclock cerr << "Time : " << 1000 * (double)clock() / (double)CLOCKS_PER_SEC << "ms\n";
#define M 1000000007
#define M2 998244353
#define INF 10000000000000000
#define MAXN 300005
#define endl "\n"
#define iip(t) \
	int t;     \
	cin >> t;
#define iip2(a, b) \
	int a, b;      \
	cin >> a >> b;
#define dip(a) \
	double a;  \
	cin >> a;
#define dip2(a, b) \
	double a, b;   \
	cin >> a >> b;
#define garr(ip)       \
	for (auto &x : ip) \
		cin >> x;
#define parr(ip)          \
	for (auto &x : ip)    \
		cout << x << " "; \
	cout << endl;
#define test   \
	int _t;    \
	cin >> _t; \
	while (_t--)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int>> vp;

int n;
map<pii, int> dp;
vi arr(MAXN);

int f(int start, int left)
{
	if (left == 0)
		return 0;
	else if (n - start + 1 < left + left - 1 or start > n)
		return -INF;
	else if (dp.find({start, left}) != dp.end())
		return dp[{start, left}];
	else
		return dp[{start, left}] = max(arr[start] + f(start + 2, left - 1), f(start + 1, left));
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	rep(i, 1, n) cin >> arr[i];
	cnl(f(1, n / 2));
}