#include<iostream>
using namespace std;

int main(){
	int n,t,g;
	int data[101];
	cin >> n >> t >> g;
	for(int i=0;i<n;i++){
		cin >> data[i];
	}
	int ans = -1;
	for(int i=0;i<n;i++){
		int now = data[i];
		int bi = 2;
		while(now <= t + g){
			if(now >= t-g && now <= t+g){
				ans = i+1;
				break;
			}
			else {
				now = data[i] * bi;
				bi++;
			}

		}
		if(ans != -1) break;
	}
	cout << ans << endl;
}