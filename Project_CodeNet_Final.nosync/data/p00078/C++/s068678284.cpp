#include <iostream>
#include <cstdio>
using namespace std;

int mass[20][20];
int num;

bool hasBlank(int n){
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mass[i][j] == -1) {
				return true;
			}
		}
	}
	return false;
}

void fill(int n, int x, int y){
	if (mass[y][x] != -1) {
			x--;
			if (x < 0) {
				x = n-1;
			}
			y = (y+1) % n;
			fill(n, x ,y);
	}else {
		mass[y][x] = num++;
	}
}

void printAnswer(int n){
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%4d", mass[i][j]);
			}
			cout << endl;
		}
}

int main(){
	int n, x, y;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				mass[i][j] = -1;
			}
		}
		num = 1;
		// 1st step
		x = n/2;
		y = n/2+1;
		mass[y][x] = num++;
		// 2nd step
		while (hasBlank(n)) {
			x = (x+1) % n;
			y = (y+1) % n;
			fill(n, x ,y);
		}
		printAnswer(n);
	}
	return 0;
}