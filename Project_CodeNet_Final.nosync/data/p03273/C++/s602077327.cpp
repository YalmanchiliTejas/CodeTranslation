#include <iostream>
#include <vector>
using namespace std;

int main(){
	int H, W;
	cin >> H >> W;
	vector<vector<char>> a = vector<vector<char>>(H, vector<char>(W, 0));
	for(int h = 0; h < H; h++){
		for(int w = 0; w < W; w++){
			cin >> a[h][w];
		}
	}
	vector<bool> h_flag = vector<bool>(H, false);
	vector<bool> w_flag = vector<bool>(W, false);
	for(int h = 0; h < H; h++){
		for(int w = 0; w < W; w++){
			if(a[h][w] == '#'){
				h_flag[h] = true;
				break;
			}
		}
	}
	for(int w = 0; w < W; w++){
		for(int h = 0; h < H; h++){
			if(a[h][w] == '#'){
				w_flag[w] = true;
				break;
			}
		}
	}
	
	
	for(int h = 0; h < H; h++){
		bool flag = false;
		for(int w = 0; w < W; w++){
			if(h_flag[h] && w_flag[w]){
				cout << a[h][w];
				flag = true;
			}
		}
		if(flag)
		cout << endl;
	}

	return 0;
}
