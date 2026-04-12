#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;

ll pate_count[51];
ll lv_length[51];



ll count_pate(ll lv, ll x) {
	if (lv == 0) {
		return x;
	}

	if (x >= lv_length[lv] - 1) {
		return pate_count[lv];
	}

	if (x == 0 || x == 1)  {
		return 0;
	}
	int ans = 0;

	if (x  <= lv_length[lv - 1] + 1) {
		return count_pate(lv - 1, x - 1);
	}

	if (x == lv_length[lv - 1] + 2) {
		return pate_count[lv - 1] + 1;
	}
	return (pate_count[lv - 1] + 1) + count_pate(lv - 1, x - 1 - lv_length[lv - 1] - 1);
}

int main() {


	pate_count[0] = 1;
	lv_length[0] = 1;
	for (int i = 1; i < 51; i++) {
		pate_count[i] = pate_count[i - 1] * 2 + 1;
		lv_length[i] = lv_length[i - 1] * 2 + 3;
	}

	ll N, X;
	cin >> N >> X;
	cout << count_pate(N, X) << endl;

	return 0;
}