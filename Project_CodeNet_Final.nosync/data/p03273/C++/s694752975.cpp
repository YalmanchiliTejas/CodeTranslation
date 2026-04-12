#include <iostream>
using namespace std;

int H, W;
char a[110][110];

bool judgeH(int i){
	for (int j = 0; j < W; j++)
		if (a[i][j] == '#') return false;
	return true;
}

bool judgeW(int j){
	for (int i = 0; i < H; i++)
		if (a[i][j] == '#') return false;
	return true;
}

int main()
{
	cin >> H >> W;
	for (int i = 0; i < H; i++){
		for (int j = 0; j < W; j++){
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < H; i++){
		if (judgeH(i)) continue;
		for (int j = 0; j < W; j++){
			if (judgeW(j)) continue;
			cout << a[i][j];
		}
		cout << endl;
	}
	return 0;
}