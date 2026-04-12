#include <iostream>
using namespace std;

int main(void){
	int n, sum = 0;

	cin >> n;

	sum = 800 * n;
	sum -= (int)(n / 15) * 200;

	cout << sum << endl;

	return 0;
}