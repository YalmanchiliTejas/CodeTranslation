#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <numeric>

#define rep(i,n) for((i)=0;i<(int)(n);i++)
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int A[8][8];
	int i;
	rep(i, N * N) {
		A[i / N][i % N] = 0;
	}
	rep(i, M) {
		int x, y;
		cin >> x >> y;
		A[x - 1][y - 1] = 1;
		A[y - 1][x - 1] = 1;
	}
	int ans = 0;
	vector<int> v(N - 1);
	iota(v.begin(), v.end(), 1);
	do {
		if (A[0][v[0]] == 0)continue;
		for (i = 1; i < N - 1; i++)
			if (A[v[i - 1]][v[i]] != 1) 
				break;
		if (i == N - 1)ans++;
	} while (next_permutation(v.begin(), v.end()));
	cout << ans;
	return 0;
}

