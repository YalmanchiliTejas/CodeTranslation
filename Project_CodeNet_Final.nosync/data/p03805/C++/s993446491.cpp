#include<iostream>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<vector>
#include<functional>
#include<algorithm>
#include<cstdio>
#include<unordered_map>
using namespace std;
typedef long long ll;
bool a[10];
int b[10], d = 0;
vector<int>e[10];
int solve(int i,int s) {
	if (s == d) return 1;
	int sum = 0;
	for (int j = 0; j < e[i].size(); j++) {
		if (a[e[i][j]]) {
			a[e[i][j]] = false;
			sum += solve(e[i][j], s | b[e[i][j]]);
			a[e[i][j]] = true;
		}
	}
	return sum;
}
int main() {
	int n, m, p = 1;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		a[i] = true;
		b[i] = p;
		d += p;
		p *= 2;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	a[0] = false;
	cout << solve(0, b[0]) << endl;
}