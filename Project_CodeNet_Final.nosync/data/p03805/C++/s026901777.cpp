#include<iostream>
#include<vector>
using namespace std;
bool check[9]{ 0 };
int dp[1 << 9][9];
int N, M;
int nl() {
	int a = 0;
	for (int i = 0; i < 9; ++i) {
		if (check[i])a += (1 << i);
	}
	return a;
}
vector<vector<int> > map(9);
int search(int, int);
int main() {
	cin >> N >> M;
	for (int i = 0; i < (1 << 9); ++i) {
		for (int j = 1; j < 9; ++j) {
			dp[i][j] = -1;
		}
	}
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}
	check[1] = true;
	cout << search(1, 1) << endl;
	return 0;
}

int search(int np, int nu) {
	if (nu == N)return 1;
	int slide = nl();
	int res = 0;
	if (dp[slide][np] > -1)return dp[slide][np];
	for (int i = 0, nmax = map[np].size(); i < nmax; ++i) {
		if (!check[map[np][i]]) {
			check[map[np][i]] = true;
			res += search(map[np][i], nu + 1);
			check[map[np][i]] = false;
		}
	}
	dp[slide][np] = res;
	return res;
}