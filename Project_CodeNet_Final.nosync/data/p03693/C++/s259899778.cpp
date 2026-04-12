#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;
int main() {
	int ans;
	int a, b,c;

	cin >> a >> b >> c;
	
	ans = a * 100 + b * 10 + c;

	if (ans %4 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}