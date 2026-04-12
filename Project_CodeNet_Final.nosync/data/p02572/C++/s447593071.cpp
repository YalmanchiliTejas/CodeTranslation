#include <bits/stdc++.h>
using namespace std;

#define int long long 

const int MOD = 1e9 + 7;

int add(int a, int b) {
	a += b;
	if (a < 0) a += MOD;
	if (a > MOD) a -= MOD;
	return a;
}

int mul(int a, int b) {
	return (a * 1ll * b) % MOD;
}

int power(int a, int b) {
	int res = 1ll;
	while (b) {
		if (b & 1) {
			res = mul(res, a);
		}
		a = mul(a, a), b >>= 1;
	}
	return res;
}

int modinv(int a) {
	return power(a, MOD - 2);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n; cin >> n;
    vector<int> v(n);
    for (auto& iter : v) {
    	cin >> iter;
    }
    int square_of_sum = 0ll;
    int sum_of_squares = 0ll;
    for (auto iter : v) {
    	sum_of_squares += (iter * iter);
    	sum_of_squares %= MOD;
    	square_of_sum += iter;
    	square_of_sum %= MOD;
    }
    square_of_sum = power(square_of_sum, 2);
    int ans = square_of_sum;
    ans -= sum_of_squares;
    if (ans < 0) ans += MOD;
    ans *= modinv(2); ans %= MOD;
    cout << ans << endl;
}