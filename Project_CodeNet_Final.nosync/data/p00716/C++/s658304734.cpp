#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int m;
	cin>>m;
	while(m--){
		int money,year,n,max=0;
		cin>>money>>year>>n;
		while(n--){
			int type,cost,remain=money;
			double riritu;
			cin>>type>>riritu>>cost;
			if(type){
				for(int i=0;i<year;++i){
					remain=remain+remain*riritu-cost;
				}
			}else{
				int risoku = 0;
				for(int i=0;i<year;++i){
					risoku+=remain*riritu;
					remain=remain-cost;
				}
				remain=remain+risoku;
			}
			if(max<remain) max=remain;
		}
		cout<<max<<endl;
	}
	return 0;
}