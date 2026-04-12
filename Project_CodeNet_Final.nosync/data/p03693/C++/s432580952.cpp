#include<iostream>
using namespace std;
int main() {
	int r, g, b, s;
	cin >> r >> g >> b;
	s = 10*g+b;
	if (s % 4 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
}