#include<cstdio>
#include<iostream>

using namespace std;

int main(void) {

	int n;

	cin >> n;

	cout << (800 * n) - (200 * (n / 15)) << "\n";

	return 0;
}