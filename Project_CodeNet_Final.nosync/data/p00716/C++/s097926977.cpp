#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int m;
	cin >> m;

	for (int i = 0; i < m; i++){
		int initmoney, year, n, maxmoney = 0;
		cin >> initmoney >> year >> n;

		for (int j = 0; j < n; j++){
			int course, charge;
			double rate;

			//入力
			cin >> course >> rate >> charge;
			int money = initmoney;

			//複利計算
			if (course == 1){
				for (int k = 0; k < year; k++){
					money = money * (1 + rate) - charge;
				}
			}

			//単利計算
			else{
				int risi = 0;
				for (int k = 0; k < year; k++){
					risi += money * rate;
					money -= charge;
				}
				money += risi;
			}
			maxmoney = max(maxmoney, money);
		}
		cout << maxmoney << endl;


	}
	return 0;
}