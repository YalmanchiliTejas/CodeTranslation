#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;


int n, m, y;

main(){
	int i,j;
	cin >> n;
	while(n--){
		double st;
		string s;
		cin >> st >> y >> m;
		int ans = 0;
		for(i=0;i<m;i++){
			int type, cost;
			double rate;
			cin >> type >> rate >> cost;
			int money = st;
			if(type){
				for(j=0;j<y;j++){
					money *= 1 + rate;
					money -= cost;
				}
			}else{
				int risi=0;
				for(j=0;j<y;j++){
					risi += money * rate;
					money -= cost;
				}
				money += risi;
			}
			ans = max(ans, money);
		}
		cout << ans << endl;
	}
	return 0;
}