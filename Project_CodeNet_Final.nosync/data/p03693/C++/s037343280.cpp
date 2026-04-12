#include <iostream>

using namespace std;

int main() {
	int r, g, b;
	cin >> r >> g >> b;
	int sum = 0;
	sum = r * 100 + g * 10 + b;
	string s;
	sum % 4 == 0 ? s = "YES" : s = "NO";
	cout << s << endl; 
	return 0;
}