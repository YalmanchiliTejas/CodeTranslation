#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int size;
	while(true){
		cin >> size;
		if(size == 0){
			break;
		}
		int maxv=-1;
		int minv = 100000000;
		int sum = 0;
		for(int i=0;i<size;i++){
			int num;
			cin >> num;
			sum += num;
			minv = min(minv,num);
			maxv = max(maxv,num);
		}
		int result = (sum-minv-maxv)/(size-2);
		cout << result << endl;
	}
	return 0;
}