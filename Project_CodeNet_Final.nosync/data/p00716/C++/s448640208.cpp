#include<iostream>

using namespace std;


int main(){
	int m,n,year,money,tempMoney,tan_fuku,interest,commision,maxNum;
	double rate;
	
	cin>>m; //データセット数
	
	for(int i=0;i<m;i++){
		maxNum=0;
		cin>>money>>year>>n; //資金、運用年数、運用種類
		
		for(int j=0;j<n;j++){
			
			interest=0;
			tempMoney=money;
			
			cin>>tan_fuku>>rate>>commision; //単利複利の別、年利率、毎年の手数料
			
			for(int k=0;k<year;k++){
				
				if(tan_fuku==0){    //0なら単利
					interest+=tempMoney*rate;
					tempMoney-=commision;
				}
				else if(tan_fuku==1){	//1なら複利
					interest=tempMoney*rate;
					tempMoney+=interest-commision;
				}
			}
			
			if(tan_fuku==0){
				tempMoney+=interest;
			}
			
			if(tempMoney>maxNum){
				maxNum=tempMoney;
			}
		}
		cout<<maxNum<<endl;
	}
}