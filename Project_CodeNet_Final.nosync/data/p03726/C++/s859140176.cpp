#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int,int> PP;

/*
    freopen("input","r",stdin);
    freopen("output","w",stdout);
*/

int N;
vector<vector<int> > G;
map<PP, int> R;

int cal(int a, int b) {
	PP p = make_pair(a, b);
	if (R.find(p) != R.end()) return R[p];
	if (G[b].size() > 2) {
		R[p] = 0;
		return 0;
	}
	if (G[b].size() == 1) {
		R[p] = 1;
		return 1;
	}
	int c = G[b][0] + G[b][1] - a;
	for (int i = 0;i < G[c].size();i++) {
		if (G[c][i] == b) continue;
		if (cal(c, G[c][i]) == 1) {
			R[p] = 1;
			return 1;
		}
	}
	R[p] = 0;
	return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    G.resize(N);
    for (int i = 1;i < N;i++) {
    	int a, b;
    	cin >> a >> b;
    	a--;
    	b--;
    	G[a].push_back(b);
    	G[b].push_back(a);
    }
    bool ok = 0;
    for (int i = 0;i < N;i++) {
    	int crt = 0;
    	for (int j = 0;j < G[i].size();j++) {
    		int k = cal(i, G[i][j]);
    		if (k > 0) crt++;
    	}
    	if (crt > 1) ok = 1;
    }
    for (int i = 0;i < N && ok == 0;i++) {
    	bool x = 1;
    	for (int j = 0;j < G[i].size() && x == 1;j++) {
    		bool y = 0;
    		int t = G[i][j];
    		for (int k = 0;k < G[t].size() && y == 0;k++) {
    			if (G[t][k] == i) continue;
    			if (cal(t, G[t][k]) == 1) y = 1;
    		}
    		if (y == 0) x = 0;
    	}
    	if (x == 1) ok = 1;
    }
    if (ok || N % 2) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}