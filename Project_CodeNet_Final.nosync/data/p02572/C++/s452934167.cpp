#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 2e5 + 100;
typedef long long ll;
ll Mod = 1e9 + 7;
ll a[N], sum[N];
int n;

int main() {
	
	cin >> n;
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	for(int i = n; i >= 1; i--) {
		sum[i] = (sum[i+1] + a[i]) % Mod;
	}
	
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		ans = (a[i]*sum[i+1]%Mod + ans) % Mod;
	}
	cout << ans << endl;
	return 0;
}