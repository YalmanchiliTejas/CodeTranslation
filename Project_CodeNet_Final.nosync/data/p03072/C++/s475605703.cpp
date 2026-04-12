#include<iostream>

using namespace std;

int main(){

	int n, ans = 0, ma = 0;
	cin >> n;
	for(int i = 0, h ; i < n ; i++){
		cin >> h;
		if(h >= ma){
			++ans;
			ma = h;
		}
	}
	cout << ans;

	return 0;
}
