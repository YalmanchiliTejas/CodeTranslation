#include <iostream>
using namespace std;

int main(void){
	int m;
	cin>>m;
	while(m--){
		int first,year,n;
			int ans = 0;
		cin>>first>>year>>n;
		for(int i=0;i<n;i++){
			int flg,tesu;
			double per;
			cin>>flg>>per>>tesu;

			int money = first;
			int sum = 0;
			for(int j=0;j<year;j++){
				if(flg){
					int b = money * per;
					money = money + b - tesu;
				}
				else{
					int b = money * per;
					money -= tesu;
					sum += b;
				}
			}
			ans = max(ans,sum+money);
		}
		cout<<ans<<endl;
	}

	return 0;
}