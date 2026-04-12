#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) std::cout << x << '\n'
#define all(a) a.begin(), a.end()
#define pb push_back
#define sz(x) ((int)(x).size())
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g * b; }
const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INF = (int)1e9;
const ll  inf = (ll)1e18;
const int mod = 1000000007;
const int MAX_N = 100010;

int n, m;
int path[10][10] = {};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	/*------------------------------*/

	cin >> n >> m;

	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		path[a][b]++;
		path[b][a]++;
	}

	vector<int> v;
	rep(i, n) v.push_back(i);

	int ans = 0;

	do {
		if (v[0] != 0) break;
		rep(i, n - 1) {
			if (path[v[i]][v[i + 1]] == 0) break;
			if (i == n - 2) ans++;
		}

	} while (next_permutation(all(v)));

	cout << ans << endl;

	return 0;
}