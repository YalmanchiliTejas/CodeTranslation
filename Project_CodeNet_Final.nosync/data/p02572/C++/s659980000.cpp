#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	long long int arr[n], sum = 0, x = 0, mod = 1000000007;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		sum %= mod;
	}
	x = 0;
	for (int i = 0; i < n - 1; i++) {
		sum = (sum - arr[i] + mod) % mod;
		x = ((x % mod) + ((sum % mod) * (arr[i] % mod)) % mod) % mod;
	}
	cout << x << endl;
}
