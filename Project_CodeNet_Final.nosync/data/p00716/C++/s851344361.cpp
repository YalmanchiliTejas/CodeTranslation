#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int m;
	cin >> m;
	for(int i = 0; i < m; i++){
		int start, years, n;
		cin >> start >> years >> n;
		vector<int> vec;
		for(int j = 0; j < n; j++){
			int type, commission;
			double rate;
			cin >> type >> rate >> commission;
			
			int money = start;
			if(type){
				for(int k = 0; k < years; k++){
					money = int(money + money * rate - commission);
				}
			}else{
				int r = 0;
				for(int k = 0; k < years; k++){
					r = int(r + money * rate);
					money -= commission;
				} 
				money += r;
			}
			vec.push_back(money);
		} 
		sort(vec.begin(), vec.end());

		cout << vec[n-1] << endl;

	}

	return 0;
}