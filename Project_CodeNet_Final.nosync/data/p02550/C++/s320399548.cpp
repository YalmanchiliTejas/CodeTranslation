//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define endl "\n"
#define all(c) (c).begin(),(c).end()

// target 4096

signed main() {
	// freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, x, m;
	cin >> n >> x >> m;
	vector<ll> pref(1);
	vector<ll> arr;
	ll p = x;
	ll i;
	while (true) {
		auto it = find(all(arr), p);
		if (it != arr.end()) {
			i = it - arr.begin();
			break;
		}
		arr.push_back(p);
		pref.push_back(pref.back()+p);
		p = p*p%m;
	}
	if (n < i) {
		cout << pref[n] << endl;
		return 0;
	}
	n -= i;
	ll k = arr.size()-i;
	cout << n/k * (pref.back() - pref[i]) + pref[n%k+i] << endl;
}
/* --- PSolving ---
 * Simplifying (getting rid of variables, conditions, code logic, etc.)
 * Reframing
 * Solving a subtask (subgoal, aux. problem, removing a condition or fixing a parameter, etc.)
 * Inducing
 * Divide and conquer
 * Working backwards
 * Visual intuition
 */
