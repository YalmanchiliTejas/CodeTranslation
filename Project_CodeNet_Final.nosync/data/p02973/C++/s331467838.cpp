#include<bits/stdc++.h>
using namespace std;
typedef long long ll; typedef double db;
typedef pair<int, int> pii; typedef pair<ll, ll> pll;
typedef vector<int> vi; typedef vector<ll> vl;
typedef vector<pii> vpii; typedef vector<pll> vpll;
#define FOR(n) for(int i=0;i<n;++i)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll gcd(ll a, ll b) { return a % b ? gcd(b, a % b) : b; }
const ll mod = 1e9 + 7; const ll inf = 0x3f3f3f3f;
ll qpow(ll a, ll b) { ll t = 1; while (b != 0) { if (b & 1)t = (t * a) % mod; a = (a * a) % mod; b >>= 1; }return t; }
ll sr[112345];
vl a;
int find(int x, int y, int val) {
	if (x == y)return x;
	int mid = x + y >> 1, temp;
	if (a[mid] >= val)temp = find(mid + 1, y, val);
	else temp = find(x, mid, val);
	return temp;
}
signed main() {
	int n;
	cin >> n;
	FOR(n)cin >> sr[i];
	a.push_back(sr[0]);
	for (int i = 1; i < n; ++i) {
		if (sr[i] <= a[a.size() - 1]) {
			a.push_back(sr[i]);
		}
		else {
			int pos = find(0, a.size() - 1, sr[i]);
			a[pos] = sr[i];
		}
	}
	cout << a.size() << endl;
	return 0;
}