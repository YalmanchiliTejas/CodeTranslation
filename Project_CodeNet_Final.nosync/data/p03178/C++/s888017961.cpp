#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const int mod = 1e9 + 7;
void add_self (int & a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}
int mul (int a, int b) {
	return (ll) a * b % mod;
}

int main() {
	string k; cin >> k;
	const int n = k.size();
	int d; cin >> d;
	vector < vector < int > > dp (d, vector < int > (2));
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		vector < vector < int > > dp_new (d, vector < int > (2));
		for (bool already_smaller : {false, true}) {
			int end = k[i] - '0';
			if (already_smaller) end = 9;
			for (int next_digit = 0; next_digit <= end; next_digit++) {
				bool smaller = already_smaller || (next_digit < end);
				for (int current_sum = 0; current_sum < d; current_sum++) {
					add_self (dp_new[(current_sum + next_digit) % d][smaller], dp[current_sum][already_smaller]);
				}
			}
		}
		dp = dp_new;
	}
	cout << (dp[0][0] + dp[0][1] - 1 + mod) % mod << endl;
	return 0;
}

