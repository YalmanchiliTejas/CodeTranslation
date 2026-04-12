#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
const ll mod = ll(1e9) + 7;
const int INF = int(1e9);


int main() {
	cin.sync_with_stdio(false);
	ll N, K;
	cin >> N >> K;
	ll ans = 0;
	if (K == 0) {
		cout << N*N<< endl;
		return 0;
	}
	reps(i, K, N) {
		ans += N - i;
	}
	int x;
	reps(i, K, N + 1) {
		if (N - i < i + 1)break;
		reps(j, i+1, N-i+1) {
			x = (N - i) / j;
			ans += ((N-i)/x - j +1)*x;
			j = (N - i) / x;

		}
	}
	cout << ans << endl;
	return 0;
}
