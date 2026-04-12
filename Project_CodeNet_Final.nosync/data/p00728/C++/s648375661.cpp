#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
	int n;
	while(cin >> n,n){
		int sum=0,cmin=1001,cmax=-1;
		for(int i=0;i<n;i++){
			int tmp;
			cin >> tmp;
			sum+=tmp;
			cmin=min(cmin,tmp);
			cmax=max(cmax,tmp);
		}
		sum-=(cmin+cmax);
		n-=2;
		cout << sum/n << endl;
	}
	return 0;
}