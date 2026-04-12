#include <iostream>
#include <vector>
#include <queue>
#define inf 1000000000

using namespace std;

int N;
int H[16], W[16];
int C[4][4];
bool rect[4][4][4][4];

const int V = 1 << 16;
vector<unsigned short> G[V];
int dist[V];

void bfs()
{
	queue<int> Q;
	
	for(int i = 0; i < V; i++) dist[i] = inf;
	dist[0] = 0;
	Q.push(0);
	
	int u;
	while(Q.size()){
		u = Q.front(); Q.pop();
		
		int next;
		for(int k = 0; k < 3; k++){
			for(int p = 0; p < 4; p++){
				for(int q = 0; q < 4; q++){
					for(int r = 0; r < 4; r++){
						for(int s = 0; s < 4; s++){
							if(!rect[p][q][r][s]) continue;
							next = u;
							for(int dx = p; dx <= q; dx++){
								for(int dy = r; dy <= s; dy++){
									if(C[dx][dy] == k) next |= (1 << (dy*4+dx));
									else next &= ~(1 << (dy*4+dx));
								}
							}
							if(dist[next] < inf) continue;
							dist[next] = dist[u] + 1;
							Q.push(next);
						}
					}
				}
			}
		}
	}
}

int main(void)
{
	cin >> N;
	
	int h, w;
	for(int i = 0; i < N; i++) cin >> H[i] >> W[i];
	
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			for(int k = 0; k < 4; k++){
				for(int l = 0; l < 4; l++){
					rect[i][j][k][l] = false;
				}
			}
		}
	}
	
	for(int j = 0; j < N; j++){
		for(int x = 1 - W[j]; x < 4; x++){
			for(int y = 1 - H[j]; y < 4; y++){
				rect[max(x, 0)][min(x+W[j],4)-1][max(y, 0)][min(y+H[j],4)-1] = true;
			}
		}
	}
	
	char c;
	for(int y = 0; y < 4; y++){
		for(int x = 0; x < 4; x++){
			cin >> c;
			if(c == 'R') C[x][y] = 0;
			if(c == 'G') C[x][y] = 1;
			if(c == 'B') C[x][y] = 2;
		}
	}
	
	bfs();
	cout << dist[V-1] << endl;
	return 0;
}