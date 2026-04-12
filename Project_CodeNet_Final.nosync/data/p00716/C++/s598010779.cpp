#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	int m;
	cin >> m;
	for(int rep=0; rep<m; rep++){
		double ini;
		int year, kind;
		cin >> ini >> year >> kind;
		int ans = 0;
		for(int i=0; i<kind; i++){
			double amount = ini;
			int mode, minus, opt=0;
			double gain;
			cin >> mode >> gain >> minus;
			for(int j=0; j<year; j++){
				if(mode==0){
					opt += amount*gain;
					amount -= minus;
				}else{
					amount = floor(amount + amount*gain -minus);
				}
			}
			ans = max(ans, (int)amount+opt);
		}
		cout << ans << endl;
	}
	return 0;
}
