#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

int main(){
	int n, m, op, r, c, sz, a;
	scanf("%d%d", &n, &m);
	vector<vector<int> > v(n + 2, vector<int>(n + 2, 2)), w;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			scanf("%d", &v[i][j]);
		}
	}
	
	while(m--){
		scanf("%d%d", &op, &r);
		if(op == 0){
			scanf("%d%d%d", &c, &sz, &a);
			for(; a > 0; a -= 90){
				w = v;
				for(int i = 0; i < sz; ++i)
				for(int j = 0; j < sz; ++j){
					w[r + i][c + j] = v[r + sz - j - 1][c + i];
				}
				w.swap(v);
			}
		}
		else if(op == 1){
			scanf("%d%d", &c, &sz);
			for(int i = r; i < r + sz; ++i)
			for(int j = c; j < c + sz; ++j){
				v[i][j] = 1 - v[i][j];
			}
		}
		else if(op == 2){
			int t = v[r][1];
			for(int i = 1; i < n; ++i){
				v[r][i] = v[r][i + 1];
			}
			v[r][n] = t;
		}
		else if(op == 3){
			int t = v[r][n];
			for(int i = n; i > 1; --i){
				v[r][i] = v[r][i - 1];
			}
			v[r][1] = t;
		}
		else{
			scanf("%d", &c);
			int t = v[r][c];
			v[r][c] = 1 - t;
			queue<int> q;
			q.push(r << 16 | c);
			while(!q.empty()){
				r = q.front() >> 16;
				c = q.front() & 0xffff;
				q.pop();
				for(int i = 0; i < 4; ++i){
					int nr = r + dy[i], nc = c + dx[i];
					if(v[nr][nc] == t){
						v[nr][nc] = 1 - t;
						q.push(nr << 16 | nc);
					}
				}
			}
		}
	}
	
	for(int i = 1; i <= n; ++i)
	for(int j = 1; j <= n; ++j){
		printf("%d%c", v[i][j], j == n ? '\n' : ' ');
	}
}