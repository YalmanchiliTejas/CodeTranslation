#include <iostream>

using namespace std;

int main() {
	int m;            // データセット数
	int n;            // 運用方法の種類数
	int max;          // 最終資金の最大値
	int init_money;   // 初期運用資金量
	int year;         // 運用年数
	int method;       // 運用方法 (0 = 単利, 1 = 複利)
	double rate;      // 年利率
	int commission;   // 毎年の手数料
	int final_money;  // 最終資金
	int sum_interest; // 利子累計
	
	//cout << "データセットの数: " << endl;
	cin >> m;
	for (int i = 0; i < m; i++) {
		max = 0;
		//cout << "初期運用資金量: " << endl;
		cin >> init_money;
		//cout << "運用年数: " << endl;
		cin >> year;
		//cout << "運用方法の種類数: " << endl;
		cin >> n;
		for (int j = 0; j < n; j++) {
			//cout << "単利or複利 年利率 毎年の手数料: " << endl;
			cin >> method >> rate >> commission;
			final_money = init_money;
			if (method == 1) {
				for (int k = 0; k < year; k++) {
					final_money =  static_cast<int> (final_money * (1 + rate)) - commission;
					//cout << final_money << endl;
				}
			} else {
				sum_interest = 0;
				for (int k = 0; k < year; k++) {
					sum_interest += static_cast<int> (final_money * rate);
					final_money -= commission;
				}
				final_money += sum_interest;
			}
			if (final_money > max) {
				max = final_money;
			}
		}
		cout << max << endl;
	}

	return 0;
}