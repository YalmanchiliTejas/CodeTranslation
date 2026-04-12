#include <iostream>
using namespace std;
int n;
int main(){
	while(cin>>n&&n){
		int p;
		int pmax=-10000000,pmin=1000000;
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>p;
			pmax=max(p,pmax);
			pmin=min(p,pmin);
			sum+=p;
		}
		cout<<(sum-(pmax+pmin))/(n-2)<<endl;
	}
	return 0;
}