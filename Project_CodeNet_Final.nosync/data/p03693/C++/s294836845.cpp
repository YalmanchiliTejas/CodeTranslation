#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;



int main() {

	int r, g, b;
	cin >> r >> g >> b;

	int a = 100 * r + 10 * g + b;

	if (a % 4 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}


