#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int hyou[100][3];
	int a;
	int b;
	int c = 0;
	int kari[2];
	int p = 1;
	char d;
	while(1) {
		cin  >> a >> d >> b;
		if (a == 0 && b == 0) {
			break;
		}
		hyou[c][0] = a;
		hyou[c][1] = b;
		c++;
	}
	
	for (int i = c-1; i >= 1; i--) {
		for (int j = 0; j <i; j++) {
			if(hyou[j][1] < hyou[j+1][1]) {
				kari[0] = hyou[j][0];
				kari[1] = hyou[j][1];
				hyou[j][0] = hyou[j+1][0];
				hyou[j][1] = hyou[j+1][1];
				hyou[j+1][0] = kari[0];
				hyou[j+1][1] = kari[1];
			}
		}
	}

	for (int i = 0; i < c-1; i++) {
		hyou[i][2] = p;
		if (hyou[i][1] > hyou[i+1][1]) {
			p++;
		}
	}
	hyou[c-1][2] = p;
	
	while (cin >> a) {
		for (int i = 0; i < c; i++) {
			if (hyou[i][0] == a) {
				cout << hyou[i][2] << endl;
				break;
			}
		}
	}
	
	return 0;
}