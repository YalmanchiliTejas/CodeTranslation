#include <fstream>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <cassert>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <regex>

#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

//#define LOCAL_DEBUG

vector<int> graph[100];

int main() {
#ifdef LOCAL_DEBUG
	freopen("input1.txt","r", stdin);
#endif
	int N, M;
	cin >> N >> M;
	REP(i, M) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	stack<set<int>> stk1;
	stack<int> stk2;
	stk1.push(set<int>());
	stk2.push(1);
	int ans = 0;
	while (stk1.size() != 0) {
		set<int> s = stk1.top(); stk1.pop();
		int ss = s.size();
		int i = stk2.top(); stk2.pop();
		s.insert(i);
		if ((int)s.size() == N) {
			ans++;
			continue;
		}
		int size = graph[i].size();
		REP(i1, size) {
			int j = graph[i][i1];
			if (s.count(j) == 0) {
				set<int> new_s;
				for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
					new_s.insert(*it);
				}
				stk1.push(new_s);
				stk2.push(j);
			}
		}
	}

	cout << ans << endl;
 	return 0;
}
