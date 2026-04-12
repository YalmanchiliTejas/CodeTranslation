/*input
10
15 12
13 10
9 6
11 8
9 6
11 8
14 12
7 6
15 14
9 8
*/
#include <bits/stdc++.h>
#define pb push_back
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define x first
#define y second
#define debug(...) cout << "[" << #__VA_ARGS__ << ": " << __VA_ARGS__ << "]\n"
#define rd() abs((int)rng())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int>pii;
const int maxn = 105;
const int mod = 1e9 + 7;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int n, nxt_id;
int arr[maxn], L[maxn], R[maxn], H[maxn], C[maxn];
vector<int>adj[maxn];
void build(int lo, int hi, int p)
{
	int id = ++nxt_id;
	if(p != 0)
		adj[p].pb(id);
	L[id] = lo, R[id] = hi;
	int mn = mod;
	for(int i = lo; i <= hi; i++)
		mn = min(mn, arr[i]);
	H[id] = mn;
	for(int i = lo; i <= hi; i++)
	{
		if(arr[i] > mn)
		{
			int j = i;
			while(j + 1 <= hi && arr[j + 1] > mn)
				++j;
			build(i, j, id);
			i = j;
		}
		else
			++C[id];
	}
}
ll pwr(ll a, ll pw)
{
	ll ret = 1;
	while(pw > 0)
	{
		if(pw & 1)
			ret = ret * a % mod;
		a = a * a % mod;
		pw >>= 1;
	}
	return ret;
}
ll dp1[maxn], dp2[maxn]; // dp1 - bottom row alternates, dp2 - total number of ways to color the histogram
void dfs(int v, int p)
{
	ll h = H[v] - H[p];
	ll p1 = 1, p12 = 1;
	for(int to : adj[v])
	{
		dfs(to, v);
		p1 = p1 * dp1[to] % mod;
		p12 = p12 * (dp1[to] + dp2[to]) % mod;
	}
	dp1[v] = pwr(2, h) * p1 % mod;
	dp2[v] = (pwr(2, C[v]) * p12 + (pwr(2, h) - 2) * p1) % mod;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> arr[i];
	build(1, n, 0);
	dfs(1, 0);
	cout << dp2[1] << "\n";
	return 0;
}