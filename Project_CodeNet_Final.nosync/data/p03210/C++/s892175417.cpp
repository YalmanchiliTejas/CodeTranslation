#include<iostream>
using namespace std;

int main() {
	int X;
	cin >> X;
	cout << ((X & 1) * (X & 6) ? "YES" : "NO");
	return 0;
}