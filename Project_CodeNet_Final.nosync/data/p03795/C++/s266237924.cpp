#include <iostream>
//#include <string>
using namespace std;

int main() {
	int N = 0, lunch = 800, paybuck = 200, x = 0, y = 0;

	cin >> N;

	x = N * lunch;
	y = N / 15;
	cout << x - y * paybuck << endl;
	
	return 0;
}