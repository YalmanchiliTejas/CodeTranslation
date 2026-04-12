#include <iostream>
#include <string> 
using namespace std;
int main() {
	int a, sum = 0;
	cin >> a;
	sum = 800 * a - 200 * (a / 15);
	cout << sum;
	return 0;
}