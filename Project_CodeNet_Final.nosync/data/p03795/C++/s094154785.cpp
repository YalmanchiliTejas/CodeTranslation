#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	cout << 800 * n - 200 * (n / 15);
	return 0;
}