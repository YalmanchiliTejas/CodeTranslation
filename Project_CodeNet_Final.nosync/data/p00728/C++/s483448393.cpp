#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin >> n;
	while(n != 0){
		int max, min;
		int ans,t;
		ans = 0;
		max = 0; min = 1000;
		for(int i = 0; i < n; i++){
			cin >> t;
			if(t > max) max = t;
			if(t < min) min = t;
			ans += t;
		}
		ans -= (max + min);
		ans /= n - 2;
		cout << ans << endl;
		cin >> n;
	}
	
	return 0;
}