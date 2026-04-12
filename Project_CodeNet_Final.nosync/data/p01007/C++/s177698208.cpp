#include <iostream>
#include <string>
#include <vector>
#include <queue>

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, n) FOR(i, 0, n)
#define MP make_pair
#define X first
#define Y second

using namespace std;

typedef pair<int, int> P;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

struct Matrix{
	int n;
	vector<vector<int> > dat;
	Matrix(int n):n(n){
		dat.resize(n);
		rep(i, n) dat[i].resize(n, 0);
	}

	void rotate(int r, int c, int size, int angle){
		int cnt = angle/90;
		Matrix sub = subMatrix(c, r, size);
		rep(i, cnt) sub.rotate();
		paste(sub, c, r);
	}

	void rotate(){
		Matrix m = (*this);
		rep(i, n) rep(j, n){
			dat[i][j] = m.dat[n-j-1][i];
		}
	}

	void Lshift(int r){
		int x = dat[r][0];
		rep(i, n-1) dat[r][i] = dat[r][i+1];
		dat[r][n-1] = x;
	}

	void Rshift(int r){
		int x = dat[r][n-1];
		for(int i = n-1; i > 0; i--) dat[r][i] = dat[r][i-1];
		dat[r][0] = x;
	}

	void reversal(int r, int c, int size){
		Matrix sub = subMatrix(c, r, size);
		rep(i, sub.n) rep(j, sub.n) {
			sub.dat[i][j] = !sub.dat[i][j];
		}
		paste(sub, c, r);
	}

	void IslandReversal(int x, int y){
		int val = dat[y][x];
		vector<P> v;
		queue<P> q;
		q.push(MP(x, y));
		vector<vector<int> > visit(n, vector<int>(n, 0));
		while(!q.empty()){
			P p = q.front();
			q.pop();
			if(visit[p.Y][p.X]) continue;
			visit[p.Y][p.X] = 1;
			v.push_back(MP(p.X, p.Y));

			rep(i, 4){
				int nx = p.X + dx[i], ny = p.Y + dy[i];
				if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if(dat[ny][nx] != val) continue;
				q.push(MP(nx, ny));
			}
		}
		val = !val;
		rep(i, v.size()){
			dat[v[i].Y][v[i].X] = val;
		}
	}

	void print(){
		rep(i, n){
			rep(j, n) cout << (j?" ":"") << dat[i][j];
			cout << endl;
		}
	}

	Matrix subMatrix(int x, int y, int size){
		Matrix sub(size);
		rep(i, size) rep(j, size){
			sub.dat[i][j] = dat[y+i][x+j];
		}
		return sub;
	}

	void paste(const Matrix &mat, int x, int y){
		rep(i, mat.n) rep(j, mat.n){
			dat[y+i][x+j] = mat.dat[i][j];
		}
	}
};

int main(){
	int n, m;
	cin >> n >> m;
	Matrix mat(n);
	rep(i, n) rep(j, n){
		cin >> mat.dat[i][j];
	}
	rep(i, m){
		int op;
		cin >> op;
		if(op == 0){
			int r, c, size, angle;
			cin >> r >> c >> size >> angle;
			mat.rotate(r-1, c-1, size, angle);
		}else if(op == 1){
			int r, c, size;
			cin >> r >> c >> size;
			mat.reversal(r-1, c-1, size);
		}else if(op == 2){
			int r;
			cin >> r;
			mat.Lshift(r-1);
		}else if(op == 3){
			int r;
			cin >> r;
			mat.Rshift(r-1);
		}else if(op == 4){
			int r, c;
			cin >> r >> c;
			mat.IslandReversal(c-1, r-1);
		}
	}
	mat.print();

	return 0;
}