#include <bits/stdc++.h>
using namespace std;
const int maxn = 800;
int main() {
	long long n, k;
	long long ans = 0;
	cin >> n >> k;
	if(k == 0){
		cout << n*n;
		return 0;
	}
	for(int i = k + 1; i <= n; ++i){
		long long numeros = (n/i) * (i - k);
		ans+= numeros;
		ans+= max((n%i - k + 1LL), 0LL);
	}
	cout << ans;
	return 0;
}
