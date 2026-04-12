#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
double tanri(long first,double rate,long price,int year){
	long rsum=0,final=first;
	for(int k=0;k<year;k++){
		rsum += final*rate;
		final -= price;
	}
	final += rsum;
	return final;
}

double hukuri(long first,double rate,long price,int year){
	long final=first;
	for(int k=0;k<year;k++){
		final += final*rate-price;
	}
	return final;
}

int main(){
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		vector<long> money;
		long first;
		int year,n;
		cin>>first;
		cin>>year;
		cin>>n;
		for(int j=0;j<n;j++){
			int p;
			double rate;
			long final,price;
			cin>>p>>rate>>price;
			if(p==0){
				final=tanri(first,rate,price,year);
			}else if(p==1){
				final=hukuri(first,rate,price,year);
			}
			money.push_back(final);
		}
		sort(money.begin(),money.end());
		cout<<money[money.size()-1]<<endl;
	}
	return 0;
}