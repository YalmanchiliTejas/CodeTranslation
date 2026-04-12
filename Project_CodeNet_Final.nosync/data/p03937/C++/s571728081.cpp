#include <iostream>
#include <string>

using namespace std;

int H, W;

string A[10];

int C[10][10];

int main(void) {

	cin >> H >> W;

	A[0] = "..........";
	string tmp;
	for (int i = 1; i <= H; i++) {
		cin >> tmp;  A[i]="."+tmp+".";
	}

	C[1][1] = 1;
	int p, q;
	p = 1; q = 1;

	do{
		while (A[p][q + 1] == '#') { q++; C[p][q] = 1; }
		if (A[p + 1][q] == '#') { p++; C[p][q] = 1; }
		else { break; }
	} while (1);

	bool ans = true;

	if (C[H][W] != 1) { ans = false; }

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			//cout << C[i][j];
			if (C[i][j] == 0 && A[i][j] == '#') { ans = false; }
		}
		//cout << endl;
	}

	if (ans) { cout << "Possible" << endl; }
	else { cout << "Impossible" << endl; }


	//system("pause");
	return 0;
}