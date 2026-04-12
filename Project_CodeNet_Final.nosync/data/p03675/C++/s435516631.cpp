//arc077_c.cpp
//Fri Jun  8 22:33:38 2018

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;

int main(){
	int n;
	cin >> n;

	int a[n];
	for (int i=0;i<n;i++){
		cin >> a[i];
	}

	int b[n];
	int flag = 0;
	int num = 0;
	for (int i=n-1;i>=0;i--){
		b[num] = a[i];
		if (flag == 0){
			num = n-1-num;
			flag = 1;
		}else {
			num = n-1-num+1;
			flag = 0;
		}
	}

	for (int i=0;i<n;i++){
		cout << b[i] << " ";
	}
	printf("\n");
}