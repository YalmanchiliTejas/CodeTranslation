#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int total = 800 * N - 200 * (N / 15);
	cout << total << endl;
}