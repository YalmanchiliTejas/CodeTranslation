#include "bits/stdc++.h"
using namespace std;
int a[300000];
int main(){
	long int N;
	bool flag = 0;
	cin >>N;
	for(int i = 1;i <= N;i++){
		cin >> a[i-1];
	}
	if(a[0]  >= 10 && a[N-1] >= 10){
		for(int k = 1;k <= N-2;k++){
		if(a[k] < 10){
			flag = 0;
			int yosi = 0;
			for(int o =1;;o++){
				if(a[k-o] >= (10*o+10)){
					yosi++;
					break;
				}
				if((k-o) == 0){
					cout << "no"<<endl;
					return 0;
				}
			}
			for(int u = 1;;u++){
				if(a[k+u] >= (10*u+10)){
					yosi++;
					break;
				}
				if((k+u) == (N-1)){
					cout << "no"<<endl;
					return 0;
				}
			}
			if(yosi == 2){
				flag = 1;
			}else{
				cout <<"no"<<endl;
				return 0;
			}
		}
		}
		flag = 1;
	}

	if(flag == 0){
		cout << "no" << endl;
	}else{
		cout << "yes" << endl;
	}

		return 0;
}