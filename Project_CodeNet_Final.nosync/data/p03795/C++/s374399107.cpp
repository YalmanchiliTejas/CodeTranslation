#include <iostream>
#include <string>
using namespace std;
int main() {
	int a, b,N;
	cin >> N;
	a = 800 * N;
	b = (N / 15) * 200;
	cout << a - b << endl;
}