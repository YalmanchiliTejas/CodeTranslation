#include <iostream>
#include <algorithm>

using namespace std;

const int N = 15;

int mat[N][N], n, m, r, c, size, o, angle;
bool vis[N][N];

void rotate(int y, int x, int size){
	static int tmp[N][N];
	for(int i=0;i<N;i++) for(int j=0;j<N;j++) tmp[i][j] = mat[i][j];
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			mat[y+i][x+j] = tmp[y+size-1-j][x+i];
		}
	}
}

void reversal(int y, int x, int size){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			mat[y+i][x+j] = 1 - mat[y+i][x+j];
		}
	}
}

void left_shift(int y){
	int tmp = mat[y][0];
	for(int i=0;i+1<n;i++) mat[y][i] = mat[y][i+1];
	mat[y][n-1] = tmp;
}

void right_shift(int y){
	int tmp = mat[y][n-1];
	for(int i=n-1;i>0;i--) mat[y][i] = mat[y][i-1];
	mat[y][0] = tmp;
}

void island_reversal(int y, int x, int col){
	static int dy[4] = {-1, 0, 1, 0};
	static int dx[4] = {0, 1, 0, -1};
	vis[y][x] = true;
	mat[y][x] = 1 - mat[y][x];
	for(int i=0;i<4;i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(min(ny, nx) < 0 || max(ny, nx) >= n) continue;
		if(mat[ny][nx] != col) continue;
		island_reversal(ny, nx, col);
	}
}

void print(){
	for(int i=0;i<n;i++){
		cout << mat[i][0];
		for(int j=1;j<n;j++){
			cout << " " << mat[i][j];
		}
		cout << endl;
	}
}

int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> mat[i][j];
	for(int i=0;i<m;i++){
		//print(); cout << endl;
		cin >> o;
		if(o == 0){//rotate
			cin >> r >> c >> size >> angle;
			r--; c--;
			for(int j=0;j<angle/90;j++) rotate(r, c, size);
		}else if(o == 1){//reversal
			cin >> r >> c >> size;
			r--; c--;
			reversal(r, c, size);
		}else if(o == 2){//left-shift
			cin >> r;
			r--;
			left_shift(r);
		}else if(o == 3){//right-shift
			cin >> r;
			r--;
			right_shift(r);
		}else if(o == 4){//island reversal
			cin >> r >> c;
			r--; c--;
			fill(vis[0], vis[3], false);
			island_reversal(r, c, mat[r][c]);
		}
	}
	print();
	return 0;
}