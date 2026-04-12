#include<iostream>
using namespace std;


int main(){
	int n;
	cin >> n;
	int H[100] = {};
	for(int i = 0;i < n;i++){
		cin >> H[i];
	}
	int max = 0;
	int ans = 0;
	for(int j = 0;j < n;j++){
		if(H[j] >= max){
			ans++;
			max = H[j];
		}
	}
	cout << ans;
	return 0;
}
