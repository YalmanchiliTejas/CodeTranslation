#include<bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;


#define ll       long long int
#define fast     ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define MOD      1000000007
#define pb       push_back
#define S        second
#define F        first
#define P 		 pair<ll,ll>
#define PI 3.1415926535897932384626433832795028
//#define ordered_set tree<ll, null_type,less_equal<>, rb_tree_tag,tree_order_statistics_node_update>

int mul(int a, int b) {
	return (long long)a * b % MOD;
}

int power(int a, int b) {
	int ans = 1;
	while (b > 0) {
		if (b & 1) ans = mul(ans, a);
		a = mul(a, a);
		b >>= 1;
	}
	return ans;
}
//bitset<400000010> b;

// ll n=100000;
ll p[1000100] = {0};
vector<ll> v[1000000];
void sieve(ll n) {
	for (ll i = 2; i * i <= n; i++) {
		if (!p[i])
			//primes.push_back(i);
			for (ll j = i; j <= n; j += i) {
				if (i != j)
					;
				p[j] = 1;
			}
	}
}


// ll nextPowerOf2(ll n)
// {
//     ll p = 1;
//     if (n && !(n & (n - 1)))
//         return n;

//     while (p < n)
//         p <<= 1;

//     return p;
// }
ll gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);

}
ll factorial(ll n)
{
	if (n == 0)
		return 1;
	return n * factorial(n - 1);
}
struct segmenttree {
	vector<int> st;
	int n;
	void init(int _n) {
		n = _n;
		st.clear();
		st.resize(4 * _n, 0);
	}

	void update(int l, int r, int indup, int val, int node) {
		if (l == r) {
			st[node] += val;
			return;
		}
		else {
			int mid = (l + r) / 2;
			if (indup >= l && indup <= mid) {
				update(l, mid, indup, val, node * 2 + 1);
			}
			else {
				update(mid + 1, r, indup, val, node * 2 + 2);
			}
			st[node] = st[2 * node + 1] + st[2 * node + 2];
		}
	}

	int query(int si, int se, int l, int r, int node) {
		if (se < l || si > r || l > r) {
			return 0;
		}
		if (si >= l && se <= r) {
			return st[node];
		}
		int mid = (si + se) / 2;
		int q1 = query(si, mid, l, r, node * 2 + 1);
		int q2 = query(mid + 1, se, l, r, node * 2 + 2);
		return q1 + q2;
	}
	int query(int l, int r) {
		return query(0, n - 1, l, r, 0);
	}
	void update(int index, int val) {
		update(0, n - 1, index, val, 0);
	}
} tree;

bool chkcow(ll n, vector<ll> &a, ll k, ll mis) {
	ll sum = 0;
	for (ll i = 0; i < n; i++) {
		if (a[i] > mis)
			sum += a[i] - mis;
		if (sum >= k)
			return true;
	}


	return false;
}
struct cmp {
	bool operator() (const pair<ll, ll> &a, const pair<ll, ll> &b )const
	{
		ll lena = a.S - a.F;
		ll lenb = b.S - b.F;
		if (lena == lenb)
			return a.F < b.F;
		return lena > lenb;
	}
};
ll dp[3001][3001][2];

ll solve(vector<ll> &a, ll i, ll j, ll turn) {
	if (i > j)
		return 0;
	if (dp[i][j][turn] != -1)
		return dp[i][j][turn];
	if (turn == 0)
		return dp[i][j][turn] = max(a[i] + solve(a, i + 1, j, 1), a[j] + solve(a, i, j - 1, 1));
	else
		return dp[i][j][turn] = min(solve(a, i + 1, j, 0), solve(a, i, j - 1, 0));

}


int32_t main()
{	fast

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	ll n;
	cin >> n;
	vector<ll> a(n + 1);
	memset(dp, -1, sizeof dp);
	ll sx, sy, s = 0;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		s += a[i];
	}
	sy = solve(a, 1, n, 1);
	sx = s - sy;
	cout << sx - sy << endl;
	return 0;

}