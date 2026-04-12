#include<iostream>
#include<string>
#include<queue>

using namespace std;

int h, w, Left = 0, nowX = 0, nowY = 0;
char box;
bool pass[9][9];

int main(){
	cin >> h >> w;
	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
			cin >> box;
			if (box == '#' && (i != 0 || j != 0)){
				Left++;
				pass[i][j] = true;
			}
		}
	}

	for (int i = 0; i < h + w - 2; i++){
		if (pass[nowY][nowX + 1]){
			nowX = nowX + 1;
			Left--;
		}
		else if (pass[nowY + 1][nowX]){
			nowY = nowY + 1;
			Left--;
		}
	}

	if (Left == 0 && nowX == w - 1 && nowY == h - 1){
		cout << "Possible\n";
	}else{
		cout << "Impossible\n";
	}

	return 0;
}