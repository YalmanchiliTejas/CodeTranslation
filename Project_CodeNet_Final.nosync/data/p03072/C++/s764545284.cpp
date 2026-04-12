#include<iostream>
#include<string>
#include<algorithm>	
#include<cmath>
using namespace std;
int main() {
	int n, h, a, b = 1; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> h;
		if (i == 1) {
			a = h;
		}
		else {
			if (a <= h) {
				b++;
				a = h;
			}
		}
	}
	cout << b << endl;
	cin >> n;
}