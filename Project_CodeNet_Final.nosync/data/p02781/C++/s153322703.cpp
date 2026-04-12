#include <iostream>
#include <string>
#include <cstring>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iomanip>
#include <fstream>
#include <unordered_set>

using namespace std;

#define REP(i, n) for(ll i = 0;i < n;i++)
#define REPR(i, n) for(ll i = n;i >= 0;i--)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
#define FORR(i, m, n) for(ll i = m;i >= n;i--)
#define REPO(i, n) for(ll i = 1;i <= n;i++)
#define ll long long
#define INF (ll)1 << 60
#define MINF (-1 * INF)
#define ALL(n) n.begin(),n.end()
#define MOD 1000000007
#define P pair<ll, ll>
	
string s;
ll k;
ll ans = 0;


ll com(ll n, ll r) {
	if (n < 0 or r < 0)return 0;
	if (n < r)return 0;
	ll res = 1;
	REPO(i, r)res = res * (n - i + 1) / i;
	return res;
}

void solve(ll a, ll b, ll c) {
	if (a == s.size()) {
		if (b == k) {
			ans++;
		}
		return;
	}
	if (s[a] - '0' == 0)solve(a + 1, b, c);
	else solve(a + 1, b, 1);
	if (b == k) return;
	FOR(i, 1, 10) {
		if (c == 0 and i > s[a] - '0')break;
		if (s[a] - '0' > i) ans += com(s.size() - 1 - a, k - b - 1) * pow(9, k - b - 1);
		else solve(a + 1, b + 1, c);
	}
}
int main() {
	cin >> s >> k;
	solve(0, 0, 0);
	cout << ans << endl;
}

