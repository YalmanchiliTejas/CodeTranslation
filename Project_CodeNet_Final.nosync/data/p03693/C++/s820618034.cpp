#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

int main(void) {
	int r, g, b;
	cin >> r >> g >> b;
	if ((10 * g + b) % 4 == 0) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}