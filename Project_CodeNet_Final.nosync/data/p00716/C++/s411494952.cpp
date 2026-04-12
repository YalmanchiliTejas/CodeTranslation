#include<iostream>

using namespace std;

int main(){
	int m; cin >> m;
	while(m--){
		int money, year, n; cin >> money >> year >> n;
		int res = 0;
		for(int i=0;i<n;i++){
			int type, t; double r; cin >> type >> r >> t;
			if(type == 0){
				int cur= 0;
				for(int j=0;j<year;j++)
					cur += (money-j*t)*r;
				res = max(res, (money-year*t)+cur);
			} else {
				int cur = money;
				for(int j=0;j<year;j++)
					cur = cur*(1+r)-t;
				res = max(res, cur);
			}
		}
		cout << res << endl;
	}
}