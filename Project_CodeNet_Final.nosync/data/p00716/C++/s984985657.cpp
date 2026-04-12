#include <iostream>
#include <cmath>

using namespace std;

int main(){

	int m;
	
	cin>>m;

	while(m--){
			
		double amo, ma = -1.0;
		int y, n;
		
		cin >> amo >> y >> n;

		for(int k=0; k<n; ++k){
			
			bool mul;
			double tmp = amo, simbuf = 0;
			double rat, tesuu;
		
			cin >> mul >> rat >> tesuu;
			
			for(int a = 0; a < y; ++a){
				
				if(mul){
					tmp += floor(rat*tmp);
				}
				else{
					simbuf += floor(rat*tmp);
				}

				tmp -= tesuu;
			}

			ma = max(ma, tmp+simbuf);
		}
		
		cout << (int)(floor(ma)) << endl;
	}
	
	return 0;
}