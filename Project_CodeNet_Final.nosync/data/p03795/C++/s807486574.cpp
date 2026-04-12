#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(void) {
	int n,a;
	cin >> n;
	a = (int)(n / 15);
	cout << 800*n-200*a << endl;
	
	return 0;
}