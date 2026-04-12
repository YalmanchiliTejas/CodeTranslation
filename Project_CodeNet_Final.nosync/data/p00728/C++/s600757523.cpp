#include <iostream>
using namespace std;


main(){
	int i,n,sum,mmin,mmax,t;
	while(cin>>n,n){
		sum=0;mmin=1000;mmax=0;
		for(i=0;i<n;i++){
			cin >> t;
			sum+=t;
			mmin = min(mmin,t);
			mmax = max(mmax,t);
		}
		cout << (sum-mmin-mmax)/(n-2) << endl;
	}
	return 0;
}