#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int WIDTH = 4;
const int MAX_N = WIDTH * WIDTH;

typedef pair<int,int> mask; // (ツづ環づつスツ閉板閉ェツ、ツづつアツづーツ塗ツづゥツつゥ)

int N;
int hs[MAX_N], ws[MAX_N];
char goal[WIDTH][WIDTH + 1];
int dist[1<<(WIDTH * WIDTH)];
bool visited[1<<(WIDTH * WIDTH)];

int solve(){
	vector<mask> masks;

	const char colors[] = "RGB";
	//ツ前ツ渉按猟敖づ全ツづづ個マツスツクツづーツ仰づ淞づつィツつュ
	for(int k=0; k<N; k++){
		for(int col=0; col<3; col++){
			for(int y=-4; y<4; y++){
				for(int x=-4; x<4; x++){
					int correct = 0, remain = (1<<(WIDTH * WIDTH)) - 1;
					for(int i=0; i<4; i++){
						for(int j=0; j<4; j++){
							if(y <= i && i < y + hs[k] && x <= j && j < x + ws[k]){
								remain ^= 1 << (i * 4 + j);
								if(goal[i][j] == colors[col]){
									correct |= 1 << (i * 4 + j);
								}
							}
						}
					}
					masks.push_back( make_pair(correct, remain) );
				}
			}
		}
	}

	sort(masks.begin(), masks.end());
	masks.erase(unique(masks.begin(), masks.end()), masks.end());

	visited[0] = true;
	queue<int> que;
	que.push(0);
	while(!que.empty()){
		int tp = que.front(); que.pop();

		for(int i=0; i<(int)masks.size(); i++){
			int next = masks[i].first | (masks[i].second & tp);
			if(!visited[next]){
				dist[next] = dist[tp] + 1;
				visited[next] = true;
				que.push(next);
			}
		}
	}

	return dist[(1<<(WIDTH*WIDTH) ) - 1];
}

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d%d ",hs+i, ws+i);
	}
	for(int i=0; i<4; i++){
		scanf("%[^\n]%*c", goal[i]);
	}

	printf("%d\n", solve());

	return 0;
}