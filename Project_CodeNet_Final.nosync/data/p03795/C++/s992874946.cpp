#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int z = 0;
	z += n * 800;
	z -= (n / 15) * 200;
	cout << z << endl;
	return 0;
}