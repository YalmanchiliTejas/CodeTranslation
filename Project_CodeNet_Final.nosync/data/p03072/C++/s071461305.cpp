#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	int n, h[20], c = 1, a = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)cin >> h[i];
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (h[j] > h[i]) {
				a = 1;
				break;
			}
		}
		if (a == 0)c = c + 1;
		a = 0;
	}
	cout << c << endl;

}