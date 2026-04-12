#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int ans = 1, max, temp;
	cin >> temp;
	max = temp;
	for(int i = 1; i < n; i++){
		cin >> temp;
		if(temp < max){
			continue;
		}
		max = temp;
		ans++;
	}
	cout << ans << endl;
	return 0;
}