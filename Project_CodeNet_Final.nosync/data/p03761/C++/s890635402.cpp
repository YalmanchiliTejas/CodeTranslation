#include <bits/stdc++.h>

using namespace std;

#define FOR(v, b, e)   for (int v = (b); v < (e); ++v)
#define REP(v, n)      FOR(v, 0, n)

#define ALL(c)         (c).begin(), (c).end()

int main () {
	int n;
	cin >> n;

	vector<string> Sn(n);
	for (auto& s : Sn) cin >> s;

	REP (i, n) sort(ALL(Sn[i]));

	string result = Sn[0];
	string tmp;
	FOR (i, 1, n) {
		tmp.clear();
		set_intersection(ALL(result), ALL(Sn[i]), inserter(tmp, tmp.end()));
		swap(tmp, result);
	}
	cout << result << endl;
}