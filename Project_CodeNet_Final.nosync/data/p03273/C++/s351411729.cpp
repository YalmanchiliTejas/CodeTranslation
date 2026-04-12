#include <iostream>

using namespace std;

int main(void)
{
	char a[100][100];
	int H, W;
	cin >> H >> W;

	for (int j = 0; j < H; j++){
		for (int i = 0; i < W; i++){
			cin >> a[j][i];
		}
	}


	for (int j = 0; j < H; j++){
		for (int i = 0; i < W; i++){
			if (a[j][i] == '#')
				break;
			if (i == W - 1)
				for (int k = 0; k < W; k++){
					a[j][k] = '*';
				}
		}
	}

	for (int i = 0; i < W; i++){
		for (int j = 0; j < H; j++){
			if (a[j][i] == '#')
				break;
			if (j == H - 1){
				for (int k = 0; k < H; k++){
					a[k][i] = '*';
				}
			}
		}
	}

	for (int j = 0; j < H; j++){
		for (int i = 0; i < W; i++){
			if (a[j][i] != '*')
				cout << a[j][i];
		}

		for (int i = 0; i < W; i++){
			if (a[j][i] == '#' || a[j][i] == '.'){
				cout << endl;
				break;
			}
		}

		
	}

	return 0;
}