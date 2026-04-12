#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	string team[10];
	int tokuten[10][4];
	string kari;
	int karikari;
	int counter = 0;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		if (counter != 0) {
			cout << endl;
		}
		for (int i = 0; i < n; i++) {
			cin >> team[i] >> tokuten[i][0] >> tokuten[i][1] >> tokuten[i][2];
			tokuten[i][3] = 3 * tokuten[i][0] + tokuten[i][2];
		}

		for (int i = n-1; i > 0; i--) {
			for (int j = 0; j < i; j++) {
				if (tokuten[j][3] < tokuten[j+1][3]) {
					kari = team[j];
					team[j] = team[j+1];
					team[j+1] = kari;
					karikari = tokuten[j][3];
					tokuten[j][3] = tokuten[j+1][3];
					tokuten[j+1][3] = karikari;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			cout << team[i] << "," << tokuten[i][3] << endl;
		}
		counter = 1;
	}
	return 0;
}