#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int N;
	cin >> N;
	cout << 800 * N - 200 * (N / 15) << endl;
	return 0;
}