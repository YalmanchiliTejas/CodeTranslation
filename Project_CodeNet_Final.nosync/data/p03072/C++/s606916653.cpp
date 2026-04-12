#include<iostream>
#include <stdio.h>
using namespace std;
int main() {
	int N;
	cin >> N;
	int a[N];
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	int cnt = 0;
	for (int x = 0; x < N; x++) {
		bool c = true;
		for (int y = 0; y < x; y++) {
			if (a[y] > a[x]) {
				c = false;
			}
		}
		if (c == true) {
			cnt += 1;
		}
	}
	cout << cnt << endl;

}