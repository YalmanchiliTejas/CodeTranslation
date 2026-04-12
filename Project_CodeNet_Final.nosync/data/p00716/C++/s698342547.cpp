#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int m; cin >> m;
	while(m-- != 0){
		int start, year, n; cin >> start >> year >> n;
		int ans = start;
		for(int i=0; i<n; i++){
			int type, fee;
			double rate;
			cin >> type >> rate >> fee;

			int tmp = start;
			if(type == 0){
				int  interest_sum=0;
				for(int j=0; j<year; j++){
					interest_sum += tmp*rate;
					tmp -= fee;
				}
				tmp = tmp+interest_sum;
			} else{
				for(int j=0; j<year; j++){
					tmp += tmp*rate;
					tmp -= fee;
				}
			}
			ans = max(ans, tmp);
		}
		cout << ans << endl;
	}
}
