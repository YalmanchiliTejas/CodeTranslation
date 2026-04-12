#include <cstdio>
#include <iostream>

using namespace std;

int nmoney(int s, double ratio, int cost, int pmomey, int year) {
	int nmoney;
	int total_ratio = 0;

	if (s == 0) {
		for (int i = 0; i < year; i++) {
			total_ratio += pmomey*ratio;
			pmomey -= cost;
		}
		nmoney = pmomey + total_ratio;
	} else if (s == 1) {
		for (int i = 0; i < year; i++) {
			pmomey += pmomey*ratio - cost;
		}
		nmoney = pmomey;
	}

	return nmoney;
}

int main(void) {
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int pmoney;
		cin >> pmoney;

		int year;
		cin >> year;

		int n;
		int money = 0;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int s, cost;
			double ratio;
			cin >> s >> ratio >> cost;
			int n;
			n = nmoney(s, ratio, cost, pmoney, year);
			if (n > money) {
				money = n;
			}
		}
		printf("%d\n", money);
	}
}