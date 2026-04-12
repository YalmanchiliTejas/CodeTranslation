#include <bits/stdc++.h>
using namespace std;

int main() {
int H, W;
int count = 0;
char a = 'x';
cin >> H >> W;
vector<vector<char>> data(H, vector<char>(W,a));
vector<vector<char>> horizon_delete(H, vector<char>(W,a));
vector<vector<char>> vertical_delete(H, vector<char>(W,a));
//データ取り込み
for (int i = 0; i < H; i++){
	for (int j = 0; j < W; j++){
    cin >> data.at(i).at(j);
    }
}

//水平成分消す
for (int i = 0; i < H; i++){
	for (int j = 0; j < W; j++){
		if (data.at(i).at(j) == '#'){
    	count++;
    	}
    }
  	if (count != 0){
    	for (int j = 0; j < W; j++){
        	horizon_delete.at(i).at(j) = data.at(i).at(j);
        }
    }
  	count = 0;
}

//垂直成分消す
for (int i = 0; i < W; i++){
	for (int j = 0; j < H; j++){
		if (horizon_delete.at(j).at(i) == '#'){
    	count++;
    	}
    }
  	//全部.なら転写しない
  	if (count != 0){
    	for (int j = 0; j < H; j++){
        	vertical_delete.at(j).at(i) = horizon_delete.at(j).at(i);
        }
    }
  	count = 0;
}
//.と＃だけ書き出す
for (int i = 0; i < H; i++){
  	count = 0;
	for (int j = 0; j < W; j++){
    	if (vertical_delete.at(i).at(j) == a){
        count++;
        }
    }
    if (count == W){
    continue;
    }
    else {
	for (int j = 0; j < W; j++){
        if (vertical_delete.at(i).at(j) != a){
    	cout << vertical_delete.at(i).at(j);
        }
    	if (j == W - 1){
    	cout << endl;
    	}
    }
    }
}
}