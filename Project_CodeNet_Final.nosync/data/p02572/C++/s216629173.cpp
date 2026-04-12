#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;

const int PI = 3.1415926535;
const int inf = 1000111222;
const int mod = 1000000007;
const int N = 100007;


int main() {
	
	ios_base :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	vector <LL> ar(n + 7);
	LL sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		sum += ar[i];
		sum %= mod;
	}
	LL ans = 0;
	for (int i = 0; i + 1 < n; i++) {
		sum = (sum - ar[i] + mod) % mod;
		ans += sum * ar[i];
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}
