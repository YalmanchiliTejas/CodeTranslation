#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <map>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

struct data {
	int x, y;
};

int main() {
	/*while (true) {
		int n, count = 0;
		cin >> n;
		if (n == 0) break;
		for (int i = 2; i < n; i++) {
			if (((n - i * (i + 1) / 2) >= 0)&&(((n - i * (i + 1) / 2) % i == 0))) count++;
		}
		cout << count << endl;
	}*/
	while (true) {
		int n, l, r;
		cin >> n >> l >> r;
		int a[51];
		if (n == 0) {
			break;
		}
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int count = 0;
		bool flag = false;
		for (int i = l; i < r + 1; i++) {
			flag = false;
			for (int j = 1; j <= n; j++) {
				if (i % a[j] == 0) {
					if (j % 2 == 1) {
						count++;
						flag = true;
						break;
					}
					else{
						flag = true;
						break;
					}
				}
				/*if (i % a[j] == 0 && j % 2 == 1) {
					count++;
					break;
				}
				else if (i % a[j] != 0 && j % 2 == 0) {
					count++;
					break;
				}*/
			}
			if (flag == false) {
				if (n % 2 == 0) {
					count++;
				}
			}
		}
		cout << count << endl;

	}
	/*
	while (true) {
		int n;
		int a[405][405];
		int l = 200;
		int r = 200;
		int u = 200;
		int d = 200;
		cin >> n;
		struct data data[201];
		data[0] = 
		for (int i = 1; i < n; i++) {
		
		}
	}*/
}

