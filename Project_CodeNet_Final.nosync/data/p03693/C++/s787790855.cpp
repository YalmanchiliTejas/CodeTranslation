#include<iostream>

using namespace std;

int main() {
	int v = 0;
	int a, b, c;
	cin >> a >> b >> c;
	v += (a * 100) + (b * 10) + c;
	
	if (v % 4 == 0)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;

}