#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include<iostream>
#include<math.h>

using namespace std;

int main() {
	int N;
	int count = 0;
	int max_height = 0;
	cin >> N;

	int height = 0;
	for (int i = 0; i < N; i++) {
		cin >> height;
		if (height >= max_height) {
			max_height = height;
			count++;
		}
	}
	cout << count << endl;
}

