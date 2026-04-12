#include<iostream>
#include <algorithm>
#include<string>
#include<math.h>
#include <functional>
using namespace std;

int main(void) {
	int H,W;
	char A[100][100];
	bool Hf[100], Wf[100];
	cin >> H >> W;
	for (int j = 0;j < H;j++) {
		for (int i = 0;i < W;i++) {
			char c;
			cin >> A[j][i];
		}
	}

	for (int j = 0;j < H;j++) {
		bool flag = true;
		for (int i = 0;i < W;i++) {
			if (A[j][i] == '#')
				flag = false;
		}
		Wf[j] = flag;
	}
	for (int j = 0;j < W;j++) {
		bool flag = true;
		for (int i = 0;i < H;i++) {
			if (A[i][j] == '#')
				flag = false;
		}
		Hf[j] = flag;
	}

	for (int j = 0;j < H;j++) {
		if (Wf[j] == false) {
			for (int i = 0;i < W;i++) {
				if (Hf[i] == false)
					cout << A[j][i];
			}
			cout << endl;
		}
	}
	return 0;

}
