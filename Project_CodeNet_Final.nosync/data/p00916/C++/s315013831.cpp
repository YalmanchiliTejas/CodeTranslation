#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <queue>
#include <stack>

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, n) FOR(i, 0, n)
#define MP make_pair

using namespace std;

typedef pair<int, int> P;

int l[55], t[55], r[55], b[55];

int x[200], y[200];

const int H = 500, W = 500;
int field[H][W];
int used[H][W];

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int main(){
	int n;
	while(cin >> n, n){
		rep(i, n){
			cin >> l[i] >> t[i] >> r[i] >> b[i];
			x[i*2] = l[i], x[i*2+1] = r[i];
			y[i*2] = t[i], y[i*2+1] = b[i];
		}
		sort(x, x+n*2);
		sort(y, y+n*2);

		map<int, int> mx, my;
		rep(i, n*2){
			mx[x[i]] = 2*i+1;
			my[y[i]] = 2*i+1;
		}

		memset(field, 0, sizeof(field));
		memset(used, 0, sizeof(used));

		rep(i, n){
			int L = mx[l[i]], R = mx[r[i]];
			int T = my[t[i]], B = my[b[i]];
			for(int i = L; i <= R; i++){
				field[T][i] = 1;
				field[B][i] = 1;
			}
			for(int i = B; i <= T; i++){
				field[i][L] = 1;
				field[i][R] = 1;
			}
		}

		int ans = 0;
		rep(i, H){
			rep(j, W){
				if(!field[i][j] && !used[i][j]){
					ans++;
					queue<P> q;
					q.push(MP(j, i));
					while(!q.empty()){
						int px = q.front().first;
						int py = q.front().second;
						q.pop();

						rep(i, 4){
							int nx = px+dx[i], ny = py+dy[i];
							if(nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
							if(field[ny][nx] || used[ny][nx]) continue;
							used[ny][nx] = 1;
							q.push(MP(nx, ny));
						}
					}
				}
			}
		} // end rep
		cout << ans << endl;

		//rep(i, 30){
		//	rep(j, 30){
		//		cout << (field[i][j]?'#':'.');
		//	}cout << endl;
		//}cout << endl;
	}


	return 0;
}