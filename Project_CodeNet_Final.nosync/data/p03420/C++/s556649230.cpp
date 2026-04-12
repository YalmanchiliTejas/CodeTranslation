#include<iostream>
using namespace std;
typedef long long ll;

ll N,K;
ll ans;

int main() {
	ans = 0;

	cin >> N>> K;

	for (ll b = K + 1; b <= N; b++) {
		for (ll i = 0; (i*b) + K <= N;i++) {
			if (i*b + K == 0) {
				//a=0を除外
				ans += (i + 1)*b - (i * b + K + 1);
			}
			else if ((i+1)*b - 1 <= N) {
				ans += (i + 1)*b - (i * b + K);
			}
			else {
				ans += N - (i * b + K) + 1;
			}
		}
	}

	cout << ans << endl;
	return 0;
}