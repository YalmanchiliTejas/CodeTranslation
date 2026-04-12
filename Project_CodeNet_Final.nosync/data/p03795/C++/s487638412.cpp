#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

int comp(const void* a, const void* b){
	return *(int*)a - *(int*)b;
}

int main() {
	int n, f;
	cin >> n;
	f = n / 15;
	cout << n * 800 - f * 200 << endl;
}