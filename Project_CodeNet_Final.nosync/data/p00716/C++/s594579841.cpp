#include <iostream>
using namespace std;
typedef long long ll;

int main(){
	int m;
	cin >> m;
	for(int i = 0; i < m; i++){
		ll money, ans = 0;
		int year, n;
		cin >> money >> year >> n;
		for(int j = 0; j < n; j++){
			int method, fee;
			ll tmpmoney, profit = 0;
			double per;
			tmpmoney = money;
			cin >> method >> per >> fee;
			if(method){
				for(int k = 0; k < year; k++){
					tmpmoney = (ll)(tmpmoney*(1+per))-fee;
				}
			} else{
				for(int k = 0; k < year; k++){
					profit += (ll)(tmpmoney*per);
					tmpmoney -= fee;
				}
			}
			ans = max(ans,tmpmoney+profit);
		}
		cout << ans << endl;
	}
}