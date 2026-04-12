#include "iostream"

using namespace std;

int main() {
	int x, y, z;
	cin >> x >> y >> z;

	int a;
	a = (x - z) / (y + z);
	
	printf("%d\n", a);
}