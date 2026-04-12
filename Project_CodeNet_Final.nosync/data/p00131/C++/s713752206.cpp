#include <iostream>
using namespace std;

int dx[] = {0,1,0,0,-1},dy[] = {1,0,-1,0,0};

int main(){
	int m;
	cin >> m;
	for(int i = 0;i < m;i++){
		int a[10][10];
		for(int j = 0;j < 10;j++){
			for(int k = 0;k < 10;k++) cin >> a[j][k];
		}
		for(int j = 0;j < 1024;j++){
			int b[10][10] = {},t[10][10];
			for(int k = 0;k < 10;k++){
				for(int l = 0;l < 10;l++){
					t[k][l] = a[k][l];
				}
			}
			for(int k = 0;k < 10;k++){
				if((j >> k) & 1){
					b[0][k] = 1;
					for(int l = 0;l < 4;l++){
						int nx = dx[l],ny = k + dy[l];
						if(ny >= 0 && ny < 10){
							t[nx][ny] = (t[nx][ny] + 1) % 2;
						}
					}
				}
			}
			for(int k = 0;k < 9;k++){
				for(int l = 0;l < 10;l++){
					if(t[k][l]){
						b[k + 1][l] = 1;
						for(int n = 0;n < 5;n++){
							int nx = k + 1 + dx[n],ny = l + dy[n];
							if(nx >= 0 && nx < 10 && ny >= 0 && ny < 10){
								t[nx][ny] = (t[nx][ny] + 1) % 2;
							}
						}
					}
				}
			}
			bool flag = true;
			for(int k = 0;k < 10;k++){
				if(t[9][k]) flag = false;
			}
			if(flag){
				for(int k = 0;k < 10;k++){
					for(int l = 0;l < 10;l++) {
						cout << (!l ? "" : " ") << b[k][l];
					}
					cout << endl;
				}
			}
		}
	}
	return 0;
}