#include<iostream>
using namespace std;

int main() {
	int X;
	cin >> X;
	cout << (((X | X << 1) & 7) == 7 ? "YES" : "NO");
	return 0;
}