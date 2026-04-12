#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	int x, a, b;
	cin >> x >> a >> b;
	if ((100 * x + a * 10 + b) % 4 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}
