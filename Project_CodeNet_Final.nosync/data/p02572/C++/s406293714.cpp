#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define x first
#define y second
#define PQ priority_queue
#define pb push_back
#define fu(i,a,j) for(int i=a;i<j;i++)
#define fd(i,a,j) for(int i=a;i>=j;i--)
#define SYNC ios::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL)
#define MOD 1000000007 
#define MOD2 1000000021
#define MAXN 2000000
#define INF 1e9
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<string> vs;

//ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll m_pow(ll a, ll b, ll M = MOD) { ll res = 1; for (; b; b >>= 1, a = (a * a) % M)if (b & 1)res = (res * a) % M; return res; }
ll gcd(ll a, ll b) { if (a < b) swap(a, b); for (; b; a %= b, swap(a, b)); return a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); };
db dis(pii a, pii b) { return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); }
int dr[] = { 0, 1, 0, -1, 1,1,-1,-1 };
int dc[] = { 1, 0, -1, 0, 1,-1,1,-1 };

int n, m, k, t;

string ansok[2] = { "NO","YES" };

ll a[200005];
ll ps[200005];
int main()
{
	SYNC;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	ll ans = 0;
	ll res = 1;
	for (int i = 1; i <= n; i++) {
		ps[i] = (ps[i - 1] + a[i]) % MOD;
	}
	for (int i = 1; i <= n; i++) {
		ans = (ans + a[i] * (ps[n] - ps[i]) % MOD) % MOD;
		if (ans < 0)
			ans += MOD;
		ans %= MOD;
	}
	//모든 곱
	if (ans < 0)
		ans += MOD;
	ans %= MOD;
	cout << ans << '\n';
	return 0;
}