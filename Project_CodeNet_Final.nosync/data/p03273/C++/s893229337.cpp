#include <bits/stdc++.h>
using namespace std;

int main() {
	int H , W ;
  	cin >> H >> W ;
    vector<vector<char>> hyo(H , vector<char>(W));
  	for(int i = 0; i < H ; i++){
    	for(int j = 0; j < W ; j++){
        	cin >> hyo.at(i).at(j);
        }
    }
    int count = 0;
    for(int i = 0; i < W - count ; i++){
    	bool flag = false;
        for(int j = 0; j < H; j++){
        	if(hyo.at(j).at(i) == '#'){
                flag = true;
            	break;
            }
        }
        if(flag == false){
        	count++;
          	for(int m = 0; m < H ; m++){
          	  for(int n = i; n < W - count ; n++){
            	  hyo.at(m).at(n) = hyo.at(m).at(n + 1);
              }
            }
            i--;
        }
    }
    for(int i = 0; i < H ; i++){
      	bool flag2 = false;
    	for(int j = 0 ; j < W - count ; j++){
        	if(hyo.at(i).at(j) == '#'){
            	flag2 = true;
            }
        }
        if(flag2 == true){
        	for(int j = 0; j < W - count ; j++){
            	cout << hyo.at(i).at(j);
            }
            cout << endl;
        }
    }
}