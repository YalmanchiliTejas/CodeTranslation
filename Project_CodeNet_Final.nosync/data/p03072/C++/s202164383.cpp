#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
using namespace std;

int main() {

	int N;
	cin >> N;

	int max = 0;

	int val;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		cin >> val;
		if (max <= val) {
			ans += 1;
			max = val;
		}
	}
	
	cout << ans << endl;

	return 0;
}