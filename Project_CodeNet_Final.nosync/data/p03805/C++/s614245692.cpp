#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>


using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a, b) make_pair(a, b)

int main() {
	int n, m;
	cin >> n >> m;

	vector< vector< int > > vs(n);
	rep (i , m) {
		int a;
		int b;
		cin >> a >> b;
		a--;b--;
		vs[a].push_back(b);
		vs[b].push_back(a);
			
	}

	vector<int> ns(n);

	iota(ns.begin(), ns.end(), 0);

	int ans = 0;
	do {
		if (ns[0] != 0) {
			continue;
		}
		bool is_ok = true;
		rep(i, n - 1) {

			int cur = ns[i];
			int next = ns[i + 1];
			bool ok = false;
			for(int v : vs[cur]) {
				if (v == next) {
					ok = true;
					break;
				}
			}
			
			if (ok == false) {
				is_ok = false;
				break;
			}

		}
		if (is_ok) {
			ans++;
		}
	} while(next_permutation(ns.begin(), ns.end()));
	cout << ans<< endl;

	return 0;
}