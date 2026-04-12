#include <iostream>
#include <algorithm>

using namespace std;

int y;
int n;
long long init;

int main() {
	int m; cin >> m;
	while (m--) {
   		cin >> init;
		cin >> y;
		cin >> n;
		long long money[n];
		for (int i = 0; i < n; i++) {
			int type; cin >> type;
			double rate; cin >> rate;
			int pay; cin >> pay;
			if (type == 0) {
				money[i] = init;
				long long interest = 0;
				for (int j = 0; j < y; j++) {
					interest += money[i] * rate;
					money[i] -= pay;
				}
				money[i] += interest;
			} else {
				money[i] = init;
				for (int j = 0; j < y; j++) {
					money[i] *= (rate + 1);
					money[i] -= pay;
				}
			}
		}

		long long max_money = money[0];
		for (int i = 1; i < n; i++) 
			max_money = max(max_money, money[i]);

		cout << max_money << endl;
	}
	return 0;
}