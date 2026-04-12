#include <iostream>
using namespace std;

long compound(long money, long year, double per, long marg) {
	for (long k = 0; k < year; k++)
	{
		money += money * per - marg;
	}
	return money;
}

long simple(long money, long year, double per, long marg) {
	long sum = 0;
	for (long i = 0; i < year; i++)
	{
		sum += money * per;
		money -= marg;
	}
	return money + sum;
}

int main() {
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		long money, year, n;
		cin >> money >> year >> n;
		
		long maxMoney = 0;
		for (int j = 0; j < n; j++) {
			int way;
			double per;
			long marg;
			cin >> way >> per >> marg;
			if (way) {
				maxMoney = max(maxMoney, compound(money, year, per, marg));
			}
			else {
				maxMoney = max(maxMoney, simple(money, year, per, marg));
			}
		}
		cout << maxMoney << endl;
	}
	return 0;
}