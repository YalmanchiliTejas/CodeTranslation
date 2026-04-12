#include <iostream>
using namespace std;

int N, X, Y;

int main() {
	cin >> N;
	X = 800*N;
	Y = N/15*200;
	cout << X-Y << endl;
}