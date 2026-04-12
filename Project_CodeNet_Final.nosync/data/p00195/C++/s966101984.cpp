#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n1, n2;
	int salesNumbers[5];
	while(cin >> n1 >> n2, n1+n2 != 0){
		int maxNum = n1+n2;
		salesNumbers[0] = n1+n2;
		for(int i = 1; i < 5; i++){
			cin >> n1 >> n2;
			salesNumbers[i] = n1+n2;
			maxNum = max(maxNum, salesNumbers[i]);
		}
		for(int i=0; i < 5; i++){
			if(maxNum == salesNumbers[i])
				cout << (char)('A'+i) << " " << maxNum << endl;
		}
	}
}