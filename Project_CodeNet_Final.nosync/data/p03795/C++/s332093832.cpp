#include<iostream>
using namespace std;
int main() {
	int N, A, B, C;
	cin >> N;
	C = N / 15;
	A = 800 * N;
	B = 200 * C;
	cout << A - B;
}