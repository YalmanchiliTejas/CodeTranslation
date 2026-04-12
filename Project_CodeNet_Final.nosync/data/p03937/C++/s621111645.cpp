#include <iostream>
#include <cstdlib>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

#define size(s) (ll)(s).size()

const ll inf = 1e9;

void bye() {
    cout << '\n';
    exit(0);
}

int n, m;
vector<vector<bool> > used;
vector<vector<char> > g;
vector<vector<pair<int, int> > > p;

bool check(int a, int b) {
	return a >= 0 && b >= 0 && a < n && b < m;
}

void dfs(int i, int j) {
	used[i][j] = 1;
	int tx = i;
	int ty = j + 1;
	if (check(tx, ty) && g[tx][ty] == '#') {
		p[tx][ty] = {i, j};
		dfs(tx, ty);
	}
	tx = i + 1;
	ty = j;
	if (check(tx, ty) && g[tx][ty] == '#') {
		p[tx][ty] = {i, j};
		dfs(tx, ty);
	}
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    used.resize(n, vector<bool>(m));
	g.resize(n, vector<char>(m));
	p.resize(n, vector<pair<int, int> >(m));
	int num = 0;
	p[0][0] = {-1, -1};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> g[i][j];
			if (g[i][j] == '#') {
				num++;
			}
		}
	}
	dfs(0, 0);
	pair<int, int> v = p[n-1][m-1];
	int pth = 1;
	while (v.first != -1 && v.second != -1) {
		pth++;
		v = p[v.first][v.second];
	}
	if (pth == num) {
		cout << "Possible";
	} else {
		cout << "Impossible";
	}
    bye();
}
