#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int n, m, k;
int d[108000];
int rev[108000];
int v[108][108];
vector<int> edge[108000];
int dist[108000];
int main(){
	fill(dist, dist + 108000, -1);
	cin >> n >> m >> k;
	for(int i = 0;i < n;i++)rev[i] = -1;
	for(int i = 0;i < m;i++){
		cin >> d[i];d[i]--;
		rev[d[i]] = i;
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < k;j++){
			cin >> v[i][j];v[i][j]--;
		}
	}
	for(int i = 0;i < (1<<m);i++){
		for(int l = 0;l < k;l++){
			int to = 0;
			for(int j = 0;j < m;j++){
				if((i >> j) % 2 == 0)continue;
				if(rev[v[d[j]][l]]== -1)continue;
				to |= 1 << rev[v[d[j]][l]];
			}
			edge[i].push_back(to);
		}
	}

	queue<int> q;
	q.push((1<<m)-1);
	dist[(1 << m)-1] = 0;
	while(!q.empty()){
		int now = q.front();q.pop();
		for(int i = 0;i < edge[now].size();i++){
			int to = edge[now][i];
			if(dist[to] != -1)continue;
			dist[to] = dist[now] + 1;
			q.push(to);
		}
	}

	cout << dist[0] << endl;
	return 0;
}