#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct ManageMethod {
	bool is_multi;
	double ratio;
	int cost;
};

ManageMethod methods[101];

int main() {
	int m;
	cin >> m;
	while(m--) {
		int init_capital, manage_year, n;
		cin >> init_capital >> manage_year >> n;
		for (int i = 0; i < n; i++) {
			cin >> methods[i].is_multi >> methods[i].ratio >> methods[i].cost;
		}

		int max_capital = 0;

		for (int i = 0; i < n; i++) {
			int current_capital = init_capital;
			int sum_r = 0;
			for (int j = 0; j < manage_year; j++) {
				int r = (int)floor(current_capital * methods[i].ratio);
				if(methods[i].is_multi) {
					current_capital += r;
				}
				else {
					sum_r += r;
				}
				current_capital -= methods[i].cost;
			}
			current_capital += sum_r;

			if(max_capital < current_capital) {
				max_capital = current_capital;
			}
		}
		cout << max_capital << endl;
	}
	return 0;
}