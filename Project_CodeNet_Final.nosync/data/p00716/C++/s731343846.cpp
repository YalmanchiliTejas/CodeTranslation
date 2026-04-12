#include<iostream>
using namespace std;

int main(){
	int m;
	cin>>m;
	for(int X=0;X<m;++X){
		int ans=0;
		int init_fund;
		int years;
		int n;

		cin>>init_fund>>years>>n;
		for(int i=0;i<n;++i){
			int final_fund=init_fund;
			int type;
			double interest;
			int charge;
			
			cin>>type>>interest>>charge;
			if( type == 0 ){
				int cumul=0;
				for(int j=0;j<years;++j){
					int B=final_fund*interest;
					final_fund-=charge;
					cumul+=B;
				}
				final_fund+=cumul;
			}else{
				for(int j=0;j<years;++j){
					int B=final_fund*interest;
					final_fund=final_fund+B-charge;
				}
			}
			ans=max(ans,final_fund);
		}
		cout<<ans<<endl;
	}
	return 0;
}