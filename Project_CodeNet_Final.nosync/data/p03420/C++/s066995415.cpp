#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int MOD = 1e9 + 7;
int main() {
	int N, K;
	cin >> N >> K;
	ll ans = 0;
	for (int b = 1; b <= N; b++) {
		int x = N / b, y = N % b;
		if (b >= K)ans += x * (b - K);
		if (y >= K)ans += y - K + 1;
		if (K == 0)ans--;
	}
  	cout<<ans<<endl;
}