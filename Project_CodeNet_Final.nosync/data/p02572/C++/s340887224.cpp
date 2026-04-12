
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
const ll MOD = 1e9 + 7;

ll A[200000];
ll S[200001];

int main() {
	int N;
	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> A[i];
	}

	for (int i=0; i<N; i++) {
		S[i+1] = (S[i] + A[i]) % MOD;
	}

	ll ans = 0;

	for (int i=0; i<N-1; i++) {
		ans = (ans + (((S[N] - S[i+1] + MOD) % MOD) * A[i]) % MOD) % MOD;
	}

	cout << ans << endl;

	return 0;
}