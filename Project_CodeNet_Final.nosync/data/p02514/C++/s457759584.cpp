#include <cstdio>
#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_W = 100;
const int MAX_N = 100*100 + 2;
const int INF = 1<<29;
const int START = MAX_N - 2;
const int GOAL = MAX_N - 1;

const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

int W, H;
int board[MAX_W][MAX_W + 1];
bool visited[MAX_W][MAX_W];
int dist[MAX_W][MAX_W];
vector< pair<int,int> > nums[MAX_N];

struct state{
	int y, x, dist;
};

int search(int y, int x, int goal){
	int ans = INF;
	for(int i=0; i<(int)nums[goal].size(); i++){
		int ty = nums[goal][i].first, tx = nums[goal][i].second;
		ans = min(ans, abs(y - ty) + abs(x - tx) + dist[ty][tx]);
	}

	return ans;
}

int solve(){
	//ÅålðT·
	int max_dig = 0, sy = -1, sx = -1;
	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			if(board[i][j] < START)max_dig = max(max_dig, board[i][j]);
			if(board[i][j] == START){
				sy = i;
				sx = j;
			}
		}
	}

	//max_dig == 0ÌêÉÓ(½¾ÌDæ)
	if(max_dig == 0){
		return search(sy, sx, GOAL);
	}

	for(int i=max_dig; i>=0; i--){
		for(int y=0; y<H; y++)for(int x=0; x<W; x++){
			if(board[y][x] == (i > 0 ? i : START)){
				dist[y][x] = search(y, x, (i==max_dig ? GOAL : i + 1));
			}
		}
	}

	return dist[sy][sx];
}

int to_int(string s){
	stringstream ss(s);
	int x;
	ss >> x;
	return x;
}

int main(){
	while(scanf("%d%d ",&W, &H), H){
		memset(dist, 0,  sizeof(dist));
		for(int i=0; i<MAX_N; i++) nums[i].clear();
		for(int i=0; i<H; i++){
			for(int j=0; j<W; j++){
				string str;
				cin >> str;
				if(str == "."){
					board[i][j] = 0;
				}
				else if(str == "S"){
					board[i][j] = START;
					nums[START].push_back(make_pair(i, j));
				}
				else if(str == "G"){
					board[i][j] = GOAL;
					nums[GOAL].push_back(make_pair(i, j));
				}
				else{
					board[i][j] = to_int(str);
					nums[board[i][j]].push_back(make_pair(i, j));
				}
			}
			cin.ignore();
		}

		printf("%d\n", solve());
	}
	return 0;
}