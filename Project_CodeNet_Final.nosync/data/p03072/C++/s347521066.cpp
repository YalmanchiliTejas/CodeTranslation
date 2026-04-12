#include<iostream>

using namespace std;

int main (){
	int n;
	int moun[n+10];
	int i,j;
	int temp;
	
	cin >> n;
	
	for (i=0; i<n; i++){
		cin >> temp;
		moun[i] = temp;
	}
	int cnt = 0;
	int flag = 0;
	
	for(i=1; i < n; i++){
		flag = 0;
		for(j=0; j<i; j++){
			if (moun[i] < moun[j]) {
				flag = 1;
				break;
			}
		}
		if(flag == 0) cnt++;
	}

	cout << cnt+1 <<endl;

	return 0;
} 