#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;

ll DP[3002][3002];
int N;
vector<ll> nums;

ll findMax(int l, int r) {
	if (DP[l][r] != -1) { return DP[l][r]; }
	if (l > r) { return 0; }

	ll c1 = nums[r] - findMax(l, r - 1);
	ll c2 = nums[l] - findMax(l + 1, r);

	DP[l][r] = max(c1, c2);
	return DP[l][r];
}

int main() {
	cin >> N;
	nums.resize(N);
	for (auto &x : nums) { cin >> x; }
	memset(DP, -1, sizeof(DP));

	cout << findMax(0, N - 1) << endl;
}