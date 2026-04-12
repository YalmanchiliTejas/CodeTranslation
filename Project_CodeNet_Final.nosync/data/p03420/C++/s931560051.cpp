#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	long long ans = 0;
	for(int i = k + 1; i <= n; ++i){
		ans += (n / i) * 1LL * (i - k);
		if(n % i >= k) ans += (n % i) - k + 1;
	}
	if(k == 0) ans -= n;
	cout << ans << endl;
	return 0;
}
