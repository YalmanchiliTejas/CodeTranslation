#include<iostream>
#include<algorithm>
#include<cassert>
#include<vector>
#include<fstream>
#include<string>
using namespace std;

int main() {
	int r, g, b;
	cin >> r >> g >> b;
	if ((2 * g + b) % 4 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}