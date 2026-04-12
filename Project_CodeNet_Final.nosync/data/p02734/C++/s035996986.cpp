#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <random>
#include <deque>
#include <bitset>
#include <string>
#include <queue>
#include <complex>
 
//#define int long long
 
#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
 
#define endl '\n'
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
mt19937 mrand(random_device{}());
 
double PI = acos((double)-1);
const ld eps = 1e-7;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 7;
const ll mod = 998244353;
	
void solve();
void scan();
 
signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}

const int S = 7e3 + 1;

ll cnt[S];

void add(ll& a, ll b) {
	a += b;
	if (a >= mod)
		a -= mod;
}

void solve() {
	int n; cin >> n;
	ll ans = 0;
	ll s; cin >> s;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	fill(cnt, cnt + S, 0);
	for (int i = 0; i < n; i++) {
		add(cnt[0], 1);
		for (int j = s; j >= a[i]; j--) {
			if (j == s) add(ans, (n - i) * 1ll * cnt[j - a[i]] % mod);
			else add(cnt[j], cnt[j - a[i]]);
		}
	}
	cout << ans << endl;
    return;
}