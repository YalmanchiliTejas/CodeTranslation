#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<string, int> P;

bool cp(const P &p1, const P &p2) {
	return p1.second > p2.second;
}

int main() {
	int n; bool f = false;
	while (cin >> n, n) {
		if (f) cout << endl;

		vector<P> v;
		for (int i = 0; i < n; ++i) {
			string str; cin >> str;
			int w, l, d; cin >> w >> l >> d;
			int p = w * 3 + d;

			v.push_back( P(str, p) );
		}
		sort( v.begin(), v.end(), cp );

		for (int i = 0; i < v.size(); ++i)
			cout << v[i].first << "," << v[i].second << endl;

		f = true;
	}
}