#include <iostream>
#include <algorithm>
using namespace std;
 
int main(){
	int H, W;
	cin >> H >> W;
	string board[H];
	for(int i = 0; i < H; i++){
		cin >> board[i];
	}
	int sharp = 0;
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			if(board[i][j] == '#'){
				sharp++;
			}
		}
	}
	if(sharp == H + W - 1){
		cout << "Possible" << endl;
	}else{
		cout << "Impossible" << endl;
	}
}