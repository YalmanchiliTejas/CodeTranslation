//============================================================================
// Name        : aoj2406.cpp
// Author      : afterCmidday
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int n, t, e, x, ans = -1;
	cin >> n >> t >> e;
	for(int i = 0;i < n;i++){
		cin >> x;
		int sum = x;
		while(sum + x <= t + e){
			sum += x;
		}
		if(t - e <= sum && sum <= t + e){
			ans = i + 1;
			break;
		}
	}
cout << ans << endl;
	return 0;
}