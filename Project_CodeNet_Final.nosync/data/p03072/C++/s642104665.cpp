#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int h[20];
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	int Ma = h[0];
	int count = 1;
	for (int i = 1; i < n; i++) {
		Ma = max(h[i], Ma);
		if (h[i] == Ma) {
			count++;
		}
	}
	cout << count << endl;
	return 0;
}