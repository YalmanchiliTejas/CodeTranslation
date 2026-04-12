#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int r, g, b; cin >> r >> g >> b;
	int k = g * 10 + b;
	cout << (k % 4 == 0 ? "YES" : "NO") << endl;
}