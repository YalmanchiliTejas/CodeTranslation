
// Problem : C - pushpush
// Contest : AtCoder Regular Contest 077
// URL : https://atcoder.jp/contests/arc077/tasks/arc077_a
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define size(x) (int)x.size()

const int N = 1e6 + 1, mod = 1e9 + 7, inf = 2e9;

int n;
bool re = 1;
deque<int> a;

int main() { cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 1, x; i <= n; i++) {
		cin >> x;
		if (re) a.push_back(x);
		else a.push_front(x);
		re ^= 1;
	}
	if (!re) reverse(a.begin(), a.end());
	for (auto x : a) cout << x << ' ';
}
