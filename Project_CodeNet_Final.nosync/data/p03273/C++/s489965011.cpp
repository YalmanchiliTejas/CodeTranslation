#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int H, W;
	char a[101][101];

	cin >> H >> W;

	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			cin >> a[i][j];

	int height = H;
	int width = W;

	int delete_row;
	while (true){
		// ぜんぶ白の行を探す
		delete_row = -1;

		for (int i = 0; i < height; i++){
			// i行目の白の数
			int white_count = 0;
			for (int j = 0; j < width; j++){
				if (a[i][j] == '.'){
					white_count++;
				}
			}
//			cout << white_count << endl;
			if (white_count == width){
				delete_row = i;
//				cout << delete_row << endl;
				break;
			}
		}
		if (delete_row < 0) break;

		if (delete_row >= 0){
			for (int i = delete_row; i < height; i++){
				for (int j = 0; j < width; j++){
					a[i][j] = a[i + 1][j];
				}
			}
			height--;
		}
	}

	int delete_column;
	while (true){
		// ぜんぶ白の列を探す
		delete_column = -1;

		for (int j = 0; j < width; j++){
			// j列目の白の数
			int white_count = 0;
			for (int i = 0; i < height; i++){
				if (a[i][j] == '.'){
					white_count++;
				}
			}
			if (white_count == height){
				delete_column = j;
//				cout << delete_column << endl;
				break;
			}
		}
		if (delete_column < 0) break;

		if (delete_column >= 0){
			for (int j = delete_column; j < width; j++){
				for (int i = 0; i < height; i++){
					a[i][j] = a[i][j+1];
				}
			}
			width--;
		}
	}

	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			cout << a[i][j];
		}
		cout << endl;
	}

	return 0;
}
