#include <iostream>

using namespace std;

int main() {
	int n;	
	cin >> n;
	int paid = 800 * n;
	int paid_back = 200 * (n / 15);
	cout << paid - paid_back;
	return 0;
}