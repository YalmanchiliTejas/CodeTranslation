#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define mem(a, b) memset(a, b, sizeof(a))

const int MOD = 1000000007;
const int MAX = (int) 1e9;
const double PI = 3.141592653589793238462643383279502884;

template <typename T, typename U>
T max(T x, U y) {
    return x > y ? x : y;
}

template <typename T, typename U>
T min(T x, U y) {
    return x < y ? x : y;
}

template<typename T>
void debug(string msg, T t) {
	cout << msg << ": " << t << "\n";
}

int toDigit(char c) { return c - '0'; }


int n;
ll a[200000], prefixSum[200000];

int main() {

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	prefixSum[0] = a[0];
	for(int i = 1; i < n - 1; i++) {
		prefixSum[i] = (prefixSum[i - 1] + a[i]) % MOD;
	}

	ll ans = 0;
	for(int i = 1; i < n; i++) {
		ans = (ans + (a[i] * prefixSum[i - 1] % MOD)) % MOD;
	}

	cout << ans << "\n";

	return 0;
}