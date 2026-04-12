#include<iostream>
using namespace std;
int main() {
	int x, y, z;
	cin >> x >> y >> z;
	int count = 0;
	int sum = z;
	while (x >= sum + y + z) {
		sum += y + z;
		count++;
	}
	cout << count << endl;
}