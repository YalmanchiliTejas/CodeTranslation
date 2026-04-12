#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int calc(int money,int year,double rate,int type,int tax){
	//cout << money << " " << year << " " << rate << " " << type << " " << tax << endl;
	if( type == 1 ){
		int ans = 0;
		for(int i = 0 ; i < year ; i++){
			money = money + money * rate - tax;
		}
		return money;
	}else{
		int ans = 0;
		for(int i = 0 ; i < year ; i++){
			ans += money * rate;
			money -= tax;
		}
		return money+ans;
	}
}
int main(){
	int T;
	cin >> T;
	while(T--){
		int money;
		int y,n;
		cin >> money >> y >> n;
		int ans = 0;
		for(int i = 0 ; i < n ; i++){
			int type,tax;
			double rate;
			cin >> type >> rate >> tax;
			ans = max( ans , calc(money,y,rate,type,tax) );
		}
		cout << ans << endl;
	}
}