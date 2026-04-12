#include <iostream>

using namespace std;

int N;
int result;

int main() {
	cin >> N;
	int total = N * 800;
	int returned = (N / 15) * 200;
	
	result = total - returned;
	cout << result;
	
	return 0;	
}