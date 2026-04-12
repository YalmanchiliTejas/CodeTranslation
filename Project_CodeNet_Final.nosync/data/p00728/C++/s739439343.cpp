#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	while(cin >> n){
		if(n==0) break;
		int m = 9999999, M = 0, sum = 0;
		for(int i=0;i<n;i++){
			int tmp; cin >> tmp;
			m = min(m,tmp);
			M = max(M,tmp);
			sum += tmp;
		}
		cout << ((sum-m-M)/(n-2)) << endl;
	}
}