#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	while(1){
		int n; cin >> n;
		if(!n) break;

		int smin= 9999, smax=-1, sum = 0;
		for(int i=0; i<n; i++){
			int tmp;
			cin >> tmp;
			sum += tmp;
			smin = min(smin, tmp);
			smax = max(smax, tmp);
		}

		cout << (sum - smin - smax) /(n-2) << endl;


	}
}
