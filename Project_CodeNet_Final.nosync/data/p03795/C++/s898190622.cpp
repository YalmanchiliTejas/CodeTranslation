#include <iostream>
using namespace std;

int main() {
	int n;
	const int a = 800;
	const int b = 200;
	cin >> n;
	cout << a*n - b*(n/15) << endl;
}