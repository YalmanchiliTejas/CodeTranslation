#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int m;
	cin >> m;
	for(int i=0;i<m;i++){
		int badget,year,kind;
		int ret=0;
		cin >> badget >> year >> kind;
		for(int j=0;j<kind;j++){
			int tmp;
			int multi;
			int plus = 0;
			double rate;
			int fee;
			tmp = badget;
			cin >> multi >> rate >> fee;
			for(int k=0;k<year;k++){
				if(multi == 0){
					plus += tmp * rate;
					tmp -= fee;
				}else{
					tmp *= 1 + rate;
					tmp -= fee;
				}
			}
			ret = max(ret, tmp+plus);
		}
		cout << ret << endl;
	}
}