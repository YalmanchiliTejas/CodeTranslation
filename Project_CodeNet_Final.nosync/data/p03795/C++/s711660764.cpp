#include <iostream>
using namespace std;

int main(void){
	int N;
	cin >> N ;
	int ans = 0;
	ans = (N * 800)- (N/15)*200;
	cout << ans;
	return 0;
}