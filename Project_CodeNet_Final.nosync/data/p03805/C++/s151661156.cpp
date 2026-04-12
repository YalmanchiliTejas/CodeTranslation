#pragma GCC optimize("Ofast", "unroll-loops")

#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define ll long long

int N, M;
int G[8][8];

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int a, b; cin >> a >> b;
		--a, --b;
		G[a][b] = 1;
		G[b][a] = 1;
	}
}

bool judge(vector<int>& lis) {
	int now = 0;
	for (int i = 0; i < N - 1; ++i) {
		if (!G[now][lis[i]])
			return false;
		now = lis[i];
	}
	return true;
}

int main() {
	input();
	ll res = 0;
	vector<int> lis(N - 1);
	for (int i = 0; i < N - 1; ++i)
		lis[i] = i + 1;
	do {
		if (judge(lis)) ++res;
	} while (next_permutation(lis.begin(), lis.end()));
	cout << res << endl;
	return 0;
}