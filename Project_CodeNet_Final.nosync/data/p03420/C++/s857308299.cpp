#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	std::ifstream in("in");
	std::cin.rdbuf(in.rdbuf());
#endif

	ll N, K;
	cin >> N >> K;

	if(K == 0){
		cout << N * N << endl;
		return 0;
	}

	ll ans = 0;
	for(ll b = 1; b <= N; b++){
		ll a = N / b;
		ans += a * max(0LL, b - K);
		ll rem = N % b;
		if(rem){
			ans += max(0LL, rem + 1 - K);
		}
	}
	cout << ans << endl;
}
