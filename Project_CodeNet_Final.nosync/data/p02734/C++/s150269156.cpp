#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<functional>
#include <random>
#include<iostream>
#include<iomanip>
using namespace std;

long long cnt[3001][3001];

int main() {
	int N, S;
	int A[3000];
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 1; i < 3001; i++) {
		cnt[0][i] = 0;
	}

	cnt[0][0] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3001; j++) {
			cnt[i][j] = cnt[i - 1][j];
			if (j == A[i-1]) {
				cnt[i][j] += i;
			}
			else if (j > A[i - 1]) {
				cnt[i][j] = (cnt[i][j] + cnt[i - 1][j - A[i - 1]]) % 998244353;
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < N + 1; i++) {
		ans += cnt[i][S];
		ans = ans % 998244353;
	}

	cout << ans;
}