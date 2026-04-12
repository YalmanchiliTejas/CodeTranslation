#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<queue>
#define ll long long
using namespace std;

int n, m, ans = 0;
bool a[8][8] = {}, b[8] = {};


int dfs(int x, int t) {
	if (t == n - 1) return ans += 1;
	for (int i = 0; i < n; i++) {
		if (a[x][i] && !b[i]) {
			b[i] = true;
			ans = dfs(i, t + 1);
			b[i] = false;
		}
	}
	return ans;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		tmp1--; tmp2--;
		a[tmp1][tmp2] = a[tmp2][tmp1] = true;
	}
	b[0] = true;
	cout << dfs(0, 0) << endl;
	return 0;
}