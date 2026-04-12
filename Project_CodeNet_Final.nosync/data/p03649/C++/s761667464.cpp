#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;


int main() {
	long long int N; cin >> N;
		vector<long long int>as;
	long long int ans = 0;
	for (int i = 0; i < N; ++i) {
		long long int a; cin >> a;
		if (a > 10000) {
			long long int k = a / (N+1);
			if (k < 100)continue;
			else {
				ans += (k - 100)*(N + 1);
				a -= (k - 100)*(N + 1);
			}
		}
		as.push_back(a);
	}
	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = 0; i < N; ++i) {
			if (as[i] >= N) {
				ans++;
				for (int j = 0; j < N; ++j) {
					as[j] += i == j ? -N : 1;
				}
				flag = true;
			}
		}
	}
	cout << ans << endl;

	return 0;
}