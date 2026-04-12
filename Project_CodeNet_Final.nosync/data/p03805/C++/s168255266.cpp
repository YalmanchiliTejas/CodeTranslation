#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define MEM(a, x) memset(a, x, sizeof(a))
#define ALL(a) a.begin(), a.end()
#define UNIQUE(a) a.erase(unique(ALL(a)), a.end())
typedef long long ll;

int n, m;

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	set<pair<int, int> > st;
	FOR(i, m) {
		int a, b;
		cin >> a >> b;
		st.insert({a-1, b-1});
		st.insert({b-1, a-1});
	}
	vector<int> v(n-1);
	FOR(i, n-1) v[i] = i+1;
	int cnt = 0;
	do {
		int s = 0;
		bool ok = true;
		FOR(i, v.size()) {
			if (!st.count({s, v[i]}) && !st.count({v[i], s})) ok = false;
			s = v[i];
		}
		if (ok) cnt++;
	} while (next_permutation(ALL(v)));
	cout << cnt << endl;
	return 0;
}