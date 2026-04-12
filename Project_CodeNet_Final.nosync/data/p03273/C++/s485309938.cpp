#include <bits/stdc++.h>
using namespace std;
int main(){
	int H, W;
	cin >> H >> W;
	vector<string> str(H);
	string non(W, '.');
	for(int i = 0; i < H; i++){
		cin >> str.at(i);
		if(str.at(i) == non){
			i--;
			H--;
		}
	}
	for(int i = 0; i < W; i++){
		bool flg = 1;
		char comp = '.';
		for(int j = 0; j < H; j++){
			if(str.at(j).at(i) != comp){
				flg = 0;
				break;
			}
			comp = str.at(j).at(i);
		}
		if(flg){
			for(int j = 0; j < H; j++)
				str.at(j).erase(str.at(j).begin()+i);
			W--;
			i--;
		}
	}
	for(int i = 0; i < H; i++)
		cout << str.at(i) << endl;
}