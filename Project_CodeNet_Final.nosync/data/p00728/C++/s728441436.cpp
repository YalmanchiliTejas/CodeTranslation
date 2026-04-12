#include <iostream>
using namespace std;
int max(int a, int b) {
	if (b < a) {
		b = a;
	}
	return b;
}
int min(int a, int b) {
	if (b > a) {
		b=a;
	}
	return b;
}
int main() {
	int s, n, t, sum=0, ave, maxi=0, mini=1000;
	while (1) {
		cin >> n;
		if (n == 0)break;
		for (t = 0; t < n; t++) {
			cin >> s;
			sum = sum + s;
			maxi = max(s,maxi);
			mini = min(s,mini);
		}
		sum = sum - maxi - mini;
		ave = sum / (n-2);
		cout << ave << endl;
		maxi = max(0,0), mini = min(1000,1000),sum=0;
	}
	return 0;
}
