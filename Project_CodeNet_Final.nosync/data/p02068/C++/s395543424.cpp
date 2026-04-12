#include <iostream>
#include <string>
#include <algorithm>
#include<vector>

using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define int long long

bool used[1010101];
vector<int>primes;
void era() {
	for (int i = 2; i < 1e6; i++) {
		if (!used[i]) {
			primes.push_back(i);
			for (int j = i; j < 1e6; j += i)used[j] = true;
		}
	}
}
signed main() {
	int N; cin >> N;
	vector<int>A(N);
	era();
	REP(i, N) {
		cin >> A[i];
		if (A[i] == 1)continue;
		primes.push_back(A[i]);
	}
	int M = primes.size();
	long long ans = 0;
	REP(i, M) {
		int tmp = 0;
		REP(j, N) {
			if (A[j] % primes[i] == 0)tmp += A[j];
		}
		ans = max(ans, tmp);
	}
	cout << ans << endl;
}
