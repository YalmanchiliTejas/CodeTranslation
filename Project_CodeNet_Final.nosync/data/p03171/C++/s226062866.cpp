#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define ll long long
#define dd double
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod (ll)(998244353)
#define sz(a) (ll)a.size()
#define all(a) a.begin(),a.end()
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define frr(i,a,b) for(ll i=a-1;i>=b;i--)
#define tc(t) ll t;cin >>t;while(t--)
#define pb emplace_back
#define ee emplace
#define rr return 0
#define mp make_pair
#define pr  pair <ll,ll>
#define ff first
#define ss second
#define pie 3.1415926535
#define inf LLONG_MAX
ll mult(ll a, ll b, ll p = mod) {return ((a % p) * (b % p)) % p;}
ll add(ll a, ll b, ll p = mod) {return (a % p + b % p) % p;}
ll fpow(ll x, ll y)
{
	ll res = 1;
	x = x % mod;
	if (x == 0) return 0;
	while (y > 0)
	{
		if (y & 1LL)
			res = (res * x) % mod;
		y = y >> 1LL;
		x = (x * x) % mod;
	}
	return res;
}
ll inv(ll a, ll p = mod) {return fpow(a, p - 2);}
bool sa(const pair<ll, ll> &a, const pair<ll, ll> &b) {return (a.second < b.second);}
bool fd(const pair<ll, ll> &a, const pair<ll, ll> &b) {return (a.first > b.first);}
bool sd(const pair<ll, ll> &a, const pair<ll, ll> &b) {return (a.second > b.second);}
ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {1, -1, 0, 0};
bool valid(ll x, ll y, ll n, ll m) {
	if (x < 0 || y < 0) {
		return false;
	}
	else if (x >= n || y >= m) {
		return false;
	}
	else
		return true;
}
#define MAXN 1000001
ll spf[MAXN];
void sieve()
{
	spf[1] = 1;
	for (ll i = 2; i < MAXN; i++)

		// marking smallest prime factor for every
		// number to be itself.
		spf[i] = i;

	// separately marking spf for every even
	// number as 2
	for (ll i = 4; i < MAXN; i += 2)
		spf[i] = 2;

	for (ll i = 3; i * i < MAXN; i++)
	{
		// checking if i is prime
		if (spf[i] == i)
		{
			// marking SPF for all numbers divisible by i
			for (ll j = i * i; j < MAXN; j += i)

				// marking spf[j] if it is not
				// previously marked
				if (spf[j] == j)
					spf[j] = i;
		}
	}
}
ll dp[3001][3001][2];
ll solve(ll *a, ll i, ll j, ll turn) {
	if (i > j)
		return 0;
	if (dp[i][j][turn] != -1)
		return dp[i][j][turn];
	if (turn == 1)
		return dp[i][j][turn] = max(a[i] + solve(a, i + 1, j, 0), a[j] + solve(a, i, j - 1, 0));
	else
		return dp[i][j][turn] = min(solve(a, i + 1, j, 1), solve(a, i, j - 1, 1));
}

int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	ll n;
	cin >> n;
	ll a[n];
	ll turn = 0, p1 = 0, p2 = 0;
	ll start = 0, end = n - 1;

	memset(dp, -1, sizeof dp);
	ll sum = 0;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	ll scoreX = solve(a, 0, n - 1, 1);
	ll scoreY = sum - scoreX;
	cout << scoreX - scoreY;
	return 0;
}
