#include <iostream>
using namespace std;

long long layer_num[51], patty_num[51];

long long getPatty(long long level, long long x) {
	if (level == 0 && x == 1) {
		return 1;
	}
	else if (level == 0 && x != 1) {
		return 0;
	}
	else {
		if (x < layer_num[level - 1] + 1) {
			return getPatty(level - 1, x - 1);
		}
		else if (x == layer_num[level - 1] + 1) {
			return patty_num[level - 1];
		}
		else if(x == layer_num[level - 1] + 2) {
			return patty_num[level - 1] + 1;
		}
		else if (x == 2 * layer_num[level - 1] + 2 || x == 2 * layer_num[level - 1] + 3) {
			return 2 * patty_num[level - 1] + 1;
		}
		else {
			return patty_num[level - 1] + 1 + getPatty(level - 1, x - (layer_num[level - 1] + 2));
		}
	}
}

int main() {
	long long N, X;
	cin >> N >> X;

	layer_num[0] = 1;
	patty_num[0] = 1;
	for (int i = 1; i <= 50; i++) {
		layer_num[i] = 2 * layer_num[i - 1] + 3;
		patty_num[i] = 2 * patty_num[i - 1] + 1;
	}

	long long ans = getPatty(N, X);
	cout << ans << endl;
}