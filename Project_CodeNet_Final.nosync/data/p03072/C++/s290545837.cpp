#include <bits/stdc++.h>

constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
constexpr int MOD = 1000000007;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int main() {
	int N;
	cin >> N;
	int m = -INF;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		if (tmp >= m) {
			ans++;
			m = tmp;
		}
	}
	cout << ans << endl;
}
