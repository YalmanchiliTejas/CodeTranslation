#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
	int n, m;
	cin >> n >> m;
	map<P, bool> mp;
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		mp[P(a, b)] = true;
		mp[P(b, a)] = true;
	}
	vector<int> def(n);
	iota(def.begin(), def.end(), 0);
	int ans = 0;
	do {
		bool elf = true;
		if (def[0] != 0) continue;
		rep(i, n - 1) {
			if (mp[P(def[i], def[i + 1])] || mp[P(def[i + 1], def[i])]) continue;
			elf = false;
		}
		if (elf) ans++;
	} while (next_permutation(def.begin(), def.end()));
	cout << ans << endl;
	return 0;
}
