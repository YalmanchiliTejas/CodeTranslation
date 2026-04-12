#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <map>
#include <unordered_map>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <bitset>
#include <stack>
#include <chrono>
#include <random>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define ll long long
#define INF 1000000000000000000
#define MOD 1000000007
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define uid uniform_int_distribution <int>
using namespace std;
// Read the question carefully and see all the given sample tests
// Think about the correctness before implementing

int main() {
	int n;
	cin >> n;
	pair <int, int> p[n];
	int mnl = MOD, mnr = 0, mxl = MOD, mxr = 0;
	for (int i = 0; i < n; i++) {
		cin >> p[i].ff >> p[i].ss;
		if (p[i].ff > p[i].ss)
			swap(p[i].ff, p[i].ss);
		mnl = min(mnl, p[i].ff);
		mnr = max(mnr, p[i].ff);
		mxl = min(mxl, p[i].ss);
		mxr = max(mxr, p[i].ss);
	}
	ll ans = 1LL * (mnr - mnl) * (mxr - mxl);
	int val = (mxr - mnl);
	sort(p, p + n);
	int tmx = p[n - 1].ff, tmn = MOD;
	// fixing minimum
	for (int i = 0; i <= n; i++) {
		ans = min(ans, 1LL * val * (tmx - min(tmn, ((i == n) ? tmn :  p[i].ff))));
		if (i == n)
			break;
		tmx = max(tmx, p[i].ss);
		tmn = min(tmn, p[i].ss);
	}
	cout << ans;
}
