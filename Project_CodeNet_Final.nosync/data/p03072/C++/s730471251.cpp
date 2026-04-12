#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n;
	int height[1005];
	int maxim = 0;
	int sum = 1;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> height[i];
	}

	maxim = height[0];
	for (int i = 1; i < n; i++) {
		if (height[i] >= maxim) {
			sum++;
			maxim = height[i];
		}
	}

	cout << sum << endl;
	return(0);
}