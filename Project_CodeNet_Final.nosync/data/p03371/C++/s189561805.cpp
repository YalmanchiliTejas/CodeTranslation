#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int32_t price_A, price_B, price_AB, max_A, max_B;
	cin >> price_A >> price_B >> price_AB >> max_A >> max_B;

	int32_t res = numeric_limits<int32_t>::max();

	for (int32_t cnt_A = 0; cnt_A <= max_A; cnt_A++) {
		int32_t cnt_AB = max(max_A - cnt_A, max_B) * 2;
		res = min(res, cnt_A * price_A + cnt_AB * price_AB);
	}

	for (int32_t cnt_B = 0; cnt_B <= max_B; cnt_B++) {
		int32_t cnt_AB = max(max_B - cnt_B, max_A) * 2;
		res = min(res, cnt_B * price_B + cnt_AB * price_AB);
	}

	for (int32_t cnt_AB = 0; cnt_AB <= max(max_A, max_B) * 2; cnt_AB += 2) {
		int32_t cnt_A = max_A - cnt_AB / 2;
		if (cnt_A < 0)
			cnt_A = 0;

		int32_t cnt_B = max_B - cnt_AB / 2;
		if (cnt_B < 0)
			cnt_B = 0;

		res = min(res, cnt_A * price_A + cnt_B * price_B + cnt_AB * price_AB);
	}

	cout << res << endl;

	return 0;
}
