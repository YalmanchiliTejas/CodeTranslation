#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	int m;
	cin >> m;
	for(int l = 0; l < m; l++){
		int initMoney;
		cin >> initMoney;
		int year;
		cin >> year;
		int n;
		cin >> n;

		int maxMoney = 0;
		for(int i = 0; i < n; i++){
			int kind;
			double per;
			int hand;
			cin >> kind >> per >> hand;
			if(kind==1){
				int leftMoney = initMoney;
				for(int j = 0; j < year; j++){
					leftMoney = leftMoney + leftMoney*per - hand;
				}
				maxMoney = max(maxMoney,leftMoney);
			}
			else{
				int leftMoney = initMoney;
				int sumRisi = 0;
				for(int j = 0; j < year; j++){
					sumRisi += leftMoney*per;
					leftMoney -= hand;
				}
				maxMoney = max(maxMoney,sumRisi+leftMoney);
			}
		}
		cout << maxMoney << endl;
	}

	return 0;
}