#include <cstdlib>
#include <iostream>
using namespace std;

template<class T> inline void chmax(T& a, const T& b) { if(b > a) a = b; }

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int m;
	cin >> m;

	for(int i = 0; i < m; ++i) {
		int money, year, n;
		cin >> money >> year >> n;

		int mx = 0;
		for(int j = 0; j < n; ++j) {
			int kind, cost;
			double p;
			cin >> kind >> p >> cost;

			int tmp = money;
			if(kind) {
				for(int k = 0; k < year; ++k)
					tmp += tmp * p - cost;
			}
			else {
				int add = 0;
				for(int k = 0; k < year; ++k) {
					add += tmp * p;
					tmp -= cost;
				}

				tmp += add;
			}

			chmax(mx, tmp);
		}

		cout << mx << endl;
	}

	return EXIT_SUCCESS;
}