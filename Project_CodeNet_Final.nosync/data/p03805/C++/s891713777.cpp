#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define dunk(a) cout << (a) << "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	map<P, bool> mp;
	rep(i, m) {
		int a, b; cin >> a >> b;
		a--; b--;
		mp[P(a, b)] = true;
		mp[P(b, a)] = true;
	}
	vector<int> a(n);
	rep(i, n) a[i] = i;
	//reverse(all(a));
	int ans = 0;
	do {
		if (a[0] != 0) continue;
		bool elf = true;
		rep(i, n - 1) {
			if (!mp[P(a[i], a[i + 1])]) elf = false;
		}
		if (elf) ans++;
	} while (next_permutation(all(a)));

	dunk(ans);

	return 0;
}