#include <iostream>
#include <vector>
using namespace std;

long long solve(int level, const vector<long long>& Nums, const vector<long long>& Pates, long long& X) {
	if (Nums[level] <= X) {
		X -= Nums[level];
		return Pates[level];
	}
	else {
		long long ans = 0;
		X--;
		if (X <= 0) return ans;
		ans += solve(level - 1, Nums, Pates, X);
		if (X <= 0)return ans;
		X--;
		ans++;
		if (X <= 0)return ans;
		ans += solve(level - 1, Nums, Pates, X);
		return ans;
	}
}

int main() {
	int N;
	long long X;
	cin >> N >> X;
	vector<long long> Nums(N + 1), Pates(N + 1);
	Nums[0] = 1ll, Pates[0] = 1ll;
	for (int i = 1; i <= N; i++) {
		Nums[i] = Nums[i - 1] * 2 + 3;
		Pates[i] = Pates[i - 1] * 2 + 1;
	}
	cout << solve(N, Nums, Pates, X);

}