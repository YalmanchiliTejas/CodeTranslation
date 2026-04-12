#include <bits/stdc++.h>
using namespace std;

int main(){
	int H,W;
  	cin >> H >> W;
  	vector<vector<char>> vec(H, vector<char>(W));
  	vector<bool> Hb(H, false);
  	vector<bool> Wb(W, false);
  	for(int i = 0; i < H;i++){
    	for(int j = 0; j < W;j++){
        	cin >> vec.at(i).at(j);
          	if(vec.at(i).at(j) == '#'){
            	Hb.at(i) = true;
              	Wb.at(j) = true;
            }
        }
    }
  	
  	for(int i = 0; i < H; i++){
    	if(Hb.at(i)){
        	for(int j = 0; j < W; j++){
            	if(Wb.at(j)){
                	cout << vec.at(i).at(j);
                }
            }
          cout << endl;
        }
    }
} 