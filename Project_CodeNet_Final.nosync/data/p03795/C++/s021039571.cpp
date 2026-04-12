#include<iostream>
using namespace std;
const int COST = 800;
const int GET = 200;
const int EAT = 15;
int main() {
	int N;
	cin >> N;
	cout << COST * N - GET * (N / EAT);
	return 0;
}