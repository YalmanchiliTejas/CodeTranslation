#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define MOD 1000000007
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

ll arr[200001];
ll sum[200001];

int main() {
	FASTIO;
	int N;
	ll ans = 0;
	cin >> N;
	FOR(i, 1, N) {
		cin >> arr[i];
	}
	sum[N] = arr[N];
	ROF(i, N - 1, 1) {
		sum[i] = (sum[i + 1] + arr[i]) % MOD;
	}
	FOR(i, 1, N - 1) {
		ans = (ans + arr[i] * sum[i + 1]) % MOD;
	}
	cout << ans;

	return 0;
}