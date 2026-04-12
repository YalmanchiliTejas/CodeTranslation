#include <iostream>
using namespace std;

int main(void){
	int n;

	while(cin>>n, n){
		int sum = 0;
		int maxS = 0, minS = 1000;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			sum += x;
			maxS = max(maxS,x);
			minS = min(minS,x);
		}
		cout<<(sum - maxS - minS) / (n - 2)<<endl;
	}
	return 0;
}