
#include<cstdio>
#include<iostream>
#include<string>
#include <algorithm>
using namespace std;

int n,x=0,y=0,z=0;
int cnt;
int main() {
	cin >> n;
	int k = n;
	x = 800 * n;
	for (int i = 0; i < n; i++) {
		if (k >= 15) {
			k = k - 15;
			cnt++;
		}
	}
	y = 200 * cnt;
	z = x - y;
	cout << z << endl;

	return 0;
}