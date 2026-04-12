#include <iostream>
#include <algorithm>
using namespace std;

int fukuri(double riritu, int tesu, int year, int money){
	for(int i = 0; i < year; i++){
		money += ((int)((double)money * riritu) - tesu);
	}
	return money;
}

int tannri(double riritu, int tesu, int year, int money){
	int risi = 0;
	for(int i = 0; i < year; i++){
		risi += (int)((double)money * riritu);
		money -= tesu;
	}
	return money + risi;
}

int main(){
	int m;
	int money;
	int year, n;
	cin >> m;
	for(int i = 0; i < m; i++){
		int result = -1;
		cin >> money >> year >> n;
		for(int j = 0; j < n; j++){
			double riritu;
			int si;
			int tesu;
			cin >> si >> riritu >> tesu;
			if(si){
				result = max(result, fukuri(riritu, tesu, year, money));
			}else{
				result = max(result, tannri(riritu, tesu, year, money));
			}
		}
		cout << result << endl;
	}
	return 0;
}