#include <iostream>
using namespace std;

int field[10][10];
int f2[10][10];
int f3[10][10];

int dx[] = {
	1, 0, -1, 0
};
int dy[] = {
	0, -1, 0, 1
};

bool inside(int x, int y){
	if(x >= 0 && x < 10 && y >= 0 && y < 10)
		return true;
	else return false;
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 10; j++){
			for(int k = 0; k < 10; k++){
				cin >> field[j][k];
			}
		}
		for(int j = 0; j < 1024; j++){
			for(int k = 0; k < 10; k++){
				for(int l = 0; l < 10; l++){
					f2[k][l] = field[k][l];
					f3[k][l] = 0;
				}
			}
			for(int k = 0; k < 10; k++){
				if(((j >> k) & 1) == 1){
					for(int l = 0; l < 4; l++){
						if(inside(k + dx[l], dy[l]))
							f2[dy[l]][k+dx[l]] = (f2[dy[l]][k+dx[l]] + 1) % 2;
					}
					f2[0][k] = (f2[0][k] + 1) % 2;
					f3[0][k] = 1;
				}
			}
			for(int k = 1; k < 10; k++){
				for(int l = 0; l < 10; l++){
					if(f2[k-1][l] == 1){
						f3[k][l] = 1;
						for(int m = 0; m < 4; m++){
							if(inside(k + dy[m], l + dx[m]))
								f2[k+dy[m]][l+dx[m]] = (f2[k+dy[m]][l+dx[m]] + 1) % 2;
						}
						f2[k][l] = (f2[k][l] + 1) % 2;
					}
				}
			}
			bool f = true;
			for(int k = 0; k < 10; k++){
				if(f2[9][k] == 1){
					f = false;
					break;
				}
			}
			if(f) break;
		}
		for(int j = 0; j < 10; j++){
			for(int k = 0; k < 9; k++){
				cout << f3[j][k] << " ";
			}
			cout << f3[j][9] << endl;
		}

	}
	return 0;
}