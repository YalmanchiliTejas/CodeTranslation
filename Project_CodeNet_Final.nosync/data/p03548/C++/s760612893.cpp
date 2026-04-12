#include <iostream>
using namespace std;

int main() {
	int x, y, z, num_people;
	cin >> x >> y >> z;
	
	for (num_people = 0;;num_people++) {
		if (((y + z) * num_people + z) > x) {
			cout << num_people - 1 << endl;
			break;
		}
	}
}