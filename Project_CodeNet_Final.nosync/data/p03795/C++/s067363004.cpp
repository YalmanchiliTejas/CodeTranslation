#include<iostream>
#include<vector>
using namespace std;
int main() {
	int N;
	int S;
	cin>> N;
	S = 800 * N - 200 * (N / 15);
	cout << S;
	return 0;
}