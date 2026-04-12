#include <iostream>
using namespace std;

int simple(int money, int year, double per, int cost) {
	int add = 0;
	for (int i = 0; i < year; i++) {
		add += money * per;
		money -= cost;
	}
	return money + add;
}

int multi(int money, int year, double per, int cost) {
	for (int i = 0; i < year; i++) {
		money += money * per - cost;
	}
	return money;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int money, year, pattern;
		cin >> money >> year >> pattern;
		int maxResult = 0;
		for (int j = 0; j < pattern; j++) {
			int way;
			cin >> way;
			double per;
			cin >> per;
			int cost;
			cin >> cost;
			
			maxResult = max(maxResult, (way) ? multi(money, year, per, cost) : simple(money, year, per, cost));
		}
		cout << maxResult << endl;
	}
	return 0;
}