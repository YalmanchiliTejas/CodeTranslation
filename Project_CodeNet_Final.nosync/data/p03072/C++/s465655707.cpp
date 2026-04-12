#include <iostream>
using namespace std;
int main() {
	int count ;
	cin >> count;
	int ans = 0;
	int max = 0;
	for(int i=0;i<count;i++){
		int tmp;
		cin >>  tmp;
		if(tmp >= max){
			ans ++;
			max = tmp;
		}
	}
	cout << ans <<endl;
	return 0;
}