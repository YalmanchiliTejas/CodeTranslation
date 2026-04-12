#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int N;
	cin >> N;

	for(int i = 0; i < N; i++) {
		int in[16][16] = {0};
		int react[3][3] = {{0,1,0},{1,1,1},{0,1,0}};

		/* input */
		for(int j = 0; j < 10; j++) {
			for(int k = 0; k < 10; k++) {
				cin >> in[j + 1][k + 1];
			}
		}

		/* search */
		for(int j = 0; j < 1U << 10; j++) {
			int ans[16][16] = {0};
			int table[16][16] = {0};
			memcpy(table, in, sizeof(in));
			for(int k = 0; k < 10; k++) {
				if(j & (1U << k)) {
					for(int l = 0; l < 3; l++) {
						for(int m = 0; m < 3; m++) {
							table[l][k + m] ^= react[l][m];
						}
					}
					ans[0][k] = 1;
				}
				else
					ans[0][k] = 0;
			}
			for(int k = 1; k < 10; k++) {
				for(int l = 0; l < 10; l++) {
					if(table[k - 1 + 1][l + 1] == 1) {
						for(int m = 0; m < 3; m++)
							for(int n = 0; n < 3; n++)
								table[k + m][l + n] ^= react[m][n];
						ans[k][l] = 1;
					}
					else
						ans[k][l] = 0;
				}
			}
			bool flag = true;
			for(int k = 0; k < 10; k++)
				if(table[10][k + 1]) {
					flag = false;
				}
			if(flag) {
				for(int k = 0; k < 10; k++) {
					for(int l = 0; l < 10; l++) {
						if(l)
							cout << " ";
						cout << ans[k][l];
					}
					cout << endl;
				}
				break;
			}
		}
	}

	return 0;
}