#include <iostream>
#include <cstring>

using namespace std;

string k;
int d, n;
int dp[10005][105][2];
const int mod = 1e9 + 7;

char str[10005];
int sum;
int rek(int at, int dd, int smaller) {
	if (at == n) {
		// cout << (dd % d == 0 ? "yes" : "naw") << "\n";
		return (dd % d == 0);
	}
	if (dp[at][dd][smaller] != -1) return dp[at][dd][smaller];

	int sol = 0;
	for (int nd = 0; nd <= (smaller ? 9 : k[at] - '0'); ++nd) {

		//str[at] = nd + '0';
		//sum += nd;
		// cout << str << " " << sum << "\n";

		int newsum = (dd + nd) % d;
		sol += rek(at + 1, newsum, smaller || (nd < (k[at] - '0')));
		sol %= mod;

		//str[at] = '\0';
		//sum -= nd;
	}

	return dp[at][dd][smaller] = sol;
}

int main() {
	cin >> k >> d;
	n = k.size();
	memset(dp, -1, sizeof dp);
	int res = rek(0, 0, 0);
	cout << (res-1 >= 0 ? res-1 : res+mod-1) << "\n";
}