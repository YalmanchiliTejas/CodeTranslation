#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <random>
#include <vector>
#include <string>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <complex>
#include <ctime>
#include <numeric>
using namespace std;

#define pb push_back
#define pii pair <int, int>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define reunique(x) (x).resize(unique(all(x)) - (x).begin())
#define ld long double
#define int long long

void SOLVE() {
	string s;
	cin >> s;
	set <char> st;
	for (char c : s) {
		st.insert(c);
	}
	if (st.size() == 1) cout << "No\n";
	else cout << "Yes\n";
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;
	cout.precision(10);
	int Q = 1;
	//cin >> Q;
	while (Q--) {
		SOLVE();
	}

	return 0;
}