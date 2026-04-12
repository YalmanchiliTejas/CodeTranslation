#include <bits/stdc++.h>
using namespace std;

int main() {
	int H , W;
    cin >> H >> W;
    vector<vector<char>> hyo(H, vector<char>(W));
    for(int i = 0; i < H; i++){
    	for(int j = 0; j < W; j++){
        	cin >> hyo.at(i).at(j);
        }
    }
    int count = 0;
    for(int i = 0; i < W - count; i++){
        bool tate_check = false;
    	for(int j = 0; j < H; j++){
        	if(hyo.at(j).at(i) == '#'){
                tate_check = true;
            	break;
            }
        }
        if(tate_check == false){
          count++;
          for(int j = 0; j < H; j++){
        	for(int k = i; k < W - count; k++){
            	hyo.at(j).at(k) = hyo.at(j).at(k + 1);
            }
          }
          i--;
        }
    }
    for(int i = 0; i < H ; i++){
        bool yoko_check = false;
    	for(int j = 0; j < W - count; j++){
        	if(hyo.at(i).at(j) == '#'){
            	yoko_check = true;
                break;
            }
        }
        if(yoko_check == true){
        	for(int j = 0; j < W - count; j++){
            	cout << hyo.at(i).at(j);
            }
            cout << endl;
        }
    }
}
