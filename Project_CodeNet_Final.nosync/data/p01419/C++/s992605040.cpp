#include <bits/stdc++.h>
using namespace std;

char c[50][50];
int R,C,M;
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

vector< pair<int,int> > bfs(int x1,int y1,int x2,int y2){
	queue< pair<int,int> > Q;
	pair<int,int> prev[50][50];
	for(int i = 0 ; i < 50 ; i++)
		for(int j = 0 ; j < 50 ; j++)
			prev[i][j] = {-1,-1};
	prev[y1][x1] = {x1,y1};
	Q.push({x1,y1});
	while( Q.size() ){
		auto q = Q.front(); Q.pop();
		for(int i = 0 ; i < 4 ; i++){
			int tx = q.first + dx[i];
			int ty = q.second + dy[i];
		
			if( tx >= 0 && tx < C && ty >= 0 && ty < R && c[ty][tx] != '#' && prev[ty][tx] == make_pair(-1,-1) ){
				prev[ty][tx] = q; 
				Q.push({tx,ty});
			}
		}
	}
	
	vector< pair<int,int> > route;
	pair<int,int> now = {x2,y2};
	while( prev[now.second][now.first] != now ){
		route.push_back(now);
		now = prev[now.second][now.first];
	}
//	cout << "(" << x1 << " " << y1 << ")-(" << x2 << " " << y2 << ")" << route.size() << endl;
	reverse(route.begin(),route.end());
	return route;
}

int cost[3][51][51];

vector<int> timing[51][51];

int main(){
	cin >> R >> C >> M;
	for(int i = 0 ; i < R ; i++){
		for(int j = 0 ; j < C ; j++){
			cin >> c[i][j];
		}
	}
	for(int k = 0 ; k < 3 ; k++){
		for(int i = 0 ; i < R ; i++){
			for(int j = 0 ; j < C ; j++){
				cin >> cost[k][i][j];
			}
		}
	}
	int px,py;
	vector< pair<int,int> > all;
	for(int i = 0 ; i < M ; i++){
		int y,x;
		cin >> y >> x;
		if(i){
			auto v = bfs(px,py,x,y);
			all.insert(all.end(),v.begin(),v.end());
		}else{
			all.push_back({x,y});
		}
		px = x;
		py = y;
	}
	for(int i = 0 ; i < all.size() ; i++){
		timing[all[i].second][all[i].first].push_back(i);
	}
	long long sum = 0;
	for(int i = 0 ; i < R ; i++){
		for(int j = 0 ; j < C ; j++){
			int sw = 0;
			int ans = 0;
			for(int k = 0 ; k < timing[i][j].size() ; k++){
				if( sw == 0 ){
					ans += cost[1][i][j]; // on
					sw ^= 1;
				}
				if(k+1 < timing[i][j].size() ){
					int l = timing[i][j][k+1] - timing[i][j][k];
					int always = l * cost[0][i][j];
					if( cost[2][i][j]+cost[1][i][j] < always ){
						ans += cost[2][i][j];
						sw ^= 1;
					}else{
						ans += always;
					}
				}else{
					ans += cost[2][i][j];
					sw ^= 1;
				}
			}
			sum += ans;
		}
	}
	cout << sum << endl;
	
}