#include <iostream>
using namespace std;

int main()
{
	int m;
	for (cin >> m; m > 0; m--) {
		int money, year, n, t, max = 0;
		double ri;
		bool fukuri;
		cin >> money >> year;
		for (cin >> n; n > 0; n--) {
			cin >> fukuri >> ri >> t;
			int get = 0, last = money;
			for (int i = 0; i < year; i++) {
				get += static_cast<int>(last*ri);
				if (fukuri) {
					last += get;
					get = 0;
				}
				last -= t;
			}
			last += get;
			if (max < last) {
				max = last;
			}
		}
		cout << max << endl;
	}

	return 0;
}