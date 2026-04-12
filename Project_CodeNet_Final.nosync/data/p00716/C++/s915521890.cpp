#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int uni_func(int start, int year, double per, int tesu)
{
	int ans = start;
	int sum = 0;

	for (int i = 0; i < year; ++i) {
		int rishi = static_cast<int>(ans * per);
		sum += rishi;
		ans = ans -  tesu;
	}

	ans += sum;

	return ans;
}

int mul_func(int start, int year, double per, int tesu)
{
	int ans = start;

	for (int i = 0; i < year; ++i) {
		ans = ans + static_cast<int>(ans * per) - tesu;
	}
	
	return ans;
}

int main()
{
	int m;
	cin >> m;

	for (int data_i = 0; data_i < m; ++data_i) {
		int start, year, n;
		cin >> start;
		cin >> year;
		cin >> n;

		vector<int> last_money(n, 0);

		for (int i = 0; i < n; ++i) {
			int type, tesu;
			double per;
			cin >> type >> per >> tesu;

			if (type) {
				last_money[i] = mul_func(start, year, per, tesu);
			}
			else {
				last_money[i] = uni_func(start, year, per, tesu);
			}
		}

		int max = last_money[0];
		for (int i = 0; i < n; ++i) {
			if (max < last_money[i]) {
				max = last_money[i];
			}
		}

		cout << max << endl;
	}

	return 0;
}