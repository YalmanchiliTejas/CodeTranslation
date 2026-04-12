#include <iostream>
using namespace std;
typedef long long int ll;
int main() {
	int N, K;
	cin >> N >> K;
	ll ans = 0;
	for(int i = 1; i <= N; i++){
		int M = N % i;
		ans += (ll)(N - M) / i * (ll)max(0, i - K);
		ans += max(0, M - K + 1);
		//cout << ans << endl;
	}
	if(K == 0) cout << (ll)N * (ll)N << endl;
	else cout << ans << endl;
	return 0;
}
