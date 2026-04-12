#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXK = -1;
const int MAXN = 1 << MAXK;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 1.01e9;

int main() {
#ifdef _MSC_VER
	freopen("input.txt", "r", stdin);
#endif

	int n;
	while (cin >> n) {
		vector<pair<int, int> > ed(n - 1);
		vector<set<int> > e(n);
		for (int i = 0; i < n - 1; i++) {
			cin >> ed[i].first >> ed[i].second;
			ed[i].first--;
			ed[i].second--;
			e[ed[i].first].insert(ed[i].second);
			e[ed[i].second].insert(ed[i].first);
		}
		//set<int> leafs;
		vector<vector<int> > neib(n);
		for (int i = 0; i < n; i++) {
			if (e[i].size() == 1) {
				//leafs.insert(i);
				neib[*e[i].begin()].push_back(i);
			}
		}
		set<pair<int, int> > st;
		for (int i = 0; i < n; i++) {
			st.insert(make_pair(-(int)neib[i].size(), i));
		}
		bool ans = 0;
		while (!st.empty()) {
			if (-st.begin()->first != 1) {
				ans = 1;
				break;
			}
			int v = st.begin()->second;
			int le = neib[v][0];
			st.erase(make_pair(-(int)neib[v].size(), v));
			st.erase(make_pair(-(int)neib[le].size(), le));
			for (int to : e[v]) {
				e[to].erase(v);
				if (to != le && e[to].size() == 1) {
					int toto = *e[to].begin();
					st.erase(make_pair(-(int)neib[toto].size(), toto));
					neib[toto].push_back(to);
					st.insert(make_pair(-(int)neib[toto].size(), toto));
				}
			}
		}
		cout << (ans ? "First" : "Second") << endl;
	}

	return 0;
}