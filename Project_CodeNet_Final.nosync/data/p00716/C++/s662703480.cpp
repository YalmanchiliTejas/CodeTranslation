#include <iostream>
#include <algorithm>

using namespace std;

int computeSimple(int initial, int year, double rate,int change){
	int money = initial;//資金
	int interestSum = 0;//積み重ねた利子の和
	for(int i=0;i<year;i++){//O(year)
		int interest = money*rate;//この年の利子
		interestSum += interest;
		money -= change;//年の最後に手数料を取る
	}
	return money + interestSum;
}

int computeCompound(int initial, int year, double rate,int change){
	int money = initial;
	for(int i=0;i<year;i++){//O(year)
		int interest = money*rate;//この年の利子
		money += interest;
		money -= change;
	}
	return money;
}

int main(){
	int m;
	cin >> m;
	for(int i=0;i<m;i++){
		int initial;//初期資金
		int year;//運用年数
		int n;//運用方法の種類の数
		cin >> initial >> year >> n;
		int maxmoney = 0;//求める最大値
		for(int j=0;j<n;j++){
			bool isCompound;//1(true)が入力されると複利
			double rate;
			int charge;//手数料
			cin >> isCompound >> rate >> charge;
			int result;//最終的なお金
			if(isCompound){
				result = computeCompound(initial,year,rate,charge);
			}else{
				result = computeSimple(initial,year,rate,charge);
			}
			maxmoney = max(result,maxmoney);
		}
		cout << maxmoney << endl;
	}
	return 0;
}

/*
<メモ>
単利:simple interest
複利:compound interest
compoundは混ぜ合わせるという意味
*/