///*
#include<iostream>
using namespace std;

int main() {

	int r, g, b, num;
	cin >> r >> g >> b;
	num = r * 100 + g * 10 + b;
	num % 4 == 0 ? cout << "YES" : cout << "NO";

	return 0;
}
//*/