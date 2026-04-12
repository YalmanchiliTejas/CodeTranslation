#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int main() {
	int r, g, b;
	cin >> r >> g >> b;
	int t = 100 * r + 10 * g + b;
	if (t % 4 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}