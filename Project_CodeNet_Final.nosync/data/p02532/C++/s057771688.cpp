#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main() {

	string code;
	char kari;
	int karii;
	int a,b,c;
	char block[100][1001] = {'\0'};

	cin >> c;

	while(1) {
		cin >> code;

		if (code == "quit") {
			break;
		} else if(code == "pop") {
			cin >> karii;
			for (int i = 1; i < 1001; i++) {
				if (block[karii+1][i] == '\0') {
					cout << block[karii+1][i-1] << endl;
					block[karii+1][i-1] = '\0';
					break;
				}
			}
		} else if(code == "push"){
			cin >> karii >> kari;
			for (int i = 0; i < 1000; i++) {
				if (block[karii+1][i] == '\0') {
					block[karii+1][i] = kari;
					break;
				}
			}
		}else {
			cin >> a >> b;
			for (int i = 0; i < 1001; i++) {
				if (block[a+1][i] == '\0') {
					kari = block[a+1][i-1];
					block[a+1][i-1] = '\0';
					break;
				}
			}
			for (int i = 0; i < 1000; i++) {
				if (block[b+1][i] == '\0') {
					block[b+1][i] = kari;
					break;
				}
			}
		}

	}

	return 0;
}