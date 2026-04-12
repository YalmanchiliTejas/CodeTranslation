#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
	int N; cin >> N;
	vector<ll> A(N);
	vector<ll> sum(N);
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		if(i == 0) sum[0] = A[i];
		else sum[i] = (sum[i - 1] + A[i]) % mod;
	}
	ll ans = 0;
	for(int i = 0; i < N; i++) {
		ll num = (sum[N - 1] - sum[i]) % mod;
		if(num < 0) num += mod;
		ans =  (ans + A[i] * num) % mod;
	}
	cout << ans << endl;
	return 0;
}
