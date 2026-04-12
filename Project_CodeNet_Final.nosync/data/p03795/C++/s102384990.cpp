#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	cout << N * 800 - 200 * (N / 15) << endl;
}