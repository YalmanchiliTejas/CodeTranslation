#include<iostream>
#include <algorithm>
#include<string>
#include<cmath>
#include <functional>
using namespace std;

int main(void) {
	int ans = 0, max = 0;;
	int N;
	int H[100] = { 0 };

	cin >>N;
	for (int i = 0; i < N;i++)
		cin >> H[i];
	max = H[0];
	ans = 1;
	for (int i = 1;i < N;i++) {
		if (max <= H[i]) {
			max = H[i];
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}