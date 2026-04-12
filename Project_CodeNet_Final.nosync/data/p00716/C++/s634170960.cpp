#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>

#define rep(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = a; i < b; i++)

using namespace std;

typedef vector<int> vi;

void pp(vi v){
	rep(i, v.size()){
		cout << v[i] << ' ';
	}
	cout << endl;
}

int simulate(int init, int years, int type, double rate, int charge){
	int intsum = 0;	// 利子合計
	int interest;	// 利子
	rep(i, years){
		interest = init*rate;
		init -= charge;
		if(type == 0){	// 単利
			intsum += interest;
		}else{			// 複利
			init += interest;
		}
	}
	return init + intsum;
}

void test_simulate(){
	cout << simulate(1000000, 5, 0, 0.03125, 3000) << endl;
	cout << simulate(1000000, 5, 1, 0.03125, 3000) << endl;
}

int main(){
	//test_simulate();
	//return 0;

	int m;
	cin >> m;
	while(m--){
		int init;	// 初期資金
		int years;	// 運用年数

		cin >> init >> years;

		int best = init;
		int n;
		cin >> n;
		while(n--){
			int type;		// 0:単利 1:複利
			double rate;	// 利率
			int charge;		// 手数料
			cin >> type >> rate >> charge;
			best = max(best, simulate(init, years, type, rate, charge));
		}
		cout << best << endl;
	}

	return 0;
}