#include <iostream>
#include<stdio.h>
using namespace std;

int main(void) {
	int N;
	cin >> N;

	cout << (800 * N) - ((N / 15) * 200) << endl;
}