#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<math.h>
using namespace std;
int main() {
	int X, Y, Z;	cin >> X >> Y >> Z;
	int sum = 2 * Z + Y;
	int people = 1;
	while (true) {
		sum += (Y + Z);
		if (sum > X) {
			cout << people << endl;
			cin >> X;
			return 0;
		}
		++people;
	}
}