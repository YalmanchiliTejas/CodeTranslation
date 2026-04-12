#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define MOD 1000000007

typedef long long ll;

using namespace std;

bool check_element(vector<int> &v, int element) {
	bool res = false;
	for (auto itr = v.begin(); itr != v.end(); ++itr) {
		if (*itr == element) {
			res = true;
			break;
		}
	}

	return res;
}

void next(map<int, vector<int>> g, int point, vector<int> visited, int max, int &ans) {
	if (g[point].empty()) {
		return;
	}

	for (auto itr = g[point].begin(); itr != g[point].end(); ++itr) {
		if (check_element(visited, *itr)) {
			continue;
		}
		else {
			visited.push_back(*itr);
			if (visited.size() == max) {
				ans++;
				return;
			}
			else {
				next(g, *itr, visited, max, ans);
				visited.pop_back();
			}
		}
	}

	return;
}

int main(){
    int N, M;
    cin >> N >> M;
    map<int, vector<int>> g;
    int ans = 0;
    REP(i, M) {
    	int a, b;
    	cin >> a >> b;
    	g[a].push_back(b);
    	g[b].push_back(a);
    }

    vector<int> visited;
    visited.push_back(1);
    next(g, 1, visited, N, ans);

    cout << ans << endl;
}
