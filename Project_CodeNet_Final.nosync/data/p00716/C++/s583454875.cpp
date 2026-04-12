#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdio>
using namespace std;

int main(void) {
	int M;
	cin >> M;
	for (int mi = 0; mi < M; mi++) {
		long long moneyInit;
		int nen;
		int typeNum;
		cin >> moneyInit >> nen >> typeNum;

		long long maxMoney = moneyInit;
		for (int ti = 0; ti < typeNum; ti++) {
			bool isHukuri;
			double rate;
			long handling;
			cin >> isHukuri >> rate >> handling;

			long long money = moneyInit;
			long long interest = 0;
			for (int ni = 0; ni < nen; ni++) {
				if (isHukuri) {
					money += money * rate;
					money -= handling;
				}else {
					interest += money * rate;
					money -= handling;
				}
			}

			maxMoney = max(maxMoney, money + interest);
		}

		cout << maxMoney << endl;
	}

	return 0;
}