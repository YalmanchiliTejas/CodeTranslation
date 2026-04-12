#include <iostream>
#include <vector>
#include <queue>
#include <utility>
const int inf = 1e9;

using namespace std;
typedef pair<int, int> P;

struct edge{
	int to, cost;
	edge(){}
	edge(int a, int b){
		to = a, cost = b;
	}
};

int A, B;
int d[15][15];
int f[105][105];
vector<edge> G[305];
int dist[305];
int S, T;

void dijkstra(int x, int y)
{
	for(int i = 1; i <= T; i++) dist[i] = inf;
	
	priority_queue< P, vector<P>, greater<P> > Q;
	dist[S] = 0;
	Q.push(make_pair(0, S));
	
	int v, d;
	while(Q.size()){
		d = Q.top().first;
		v = Q.top().second;
		Q.pop();
		if(dist[v] < d) continue;
		for(int i = 0; i < G[v].size(); i++){
			int c = G[v][i].cost;
			if(G[v][i].cost == -1) c = x;
			if(G[v][i].cost == -2) c = y;
			if(dist[G[v][i].to] > d + c){
				dist[G[v][i].to] = d + c;
				Q.push(make_pair(dist[G[v][i].to], G[v][i].to));
			}
		}
	}
}

int main(void)
{
	cin >> A >> B;
	for(int x = 1; x <= A; x++){
		for(int y = 1; y <= B; y++){
			cin >> d[x][y];
		}
	}
	
	for(int a = 0; a <= 100; a++){
		for(int b = 0; b <= 100; b++){
			int val = 0;
			for(int x = 1; x <= A; x++){
				for(int y = 1; y <= B; y++){
					val = max(val, d[x][y] - a*x - b*y);
				}
			}
			f[a][b] = val;
		}
	}
	
	/*for(int a = 0; a <= 2; a++){
		for(int b = 0; b <= 2; b++){
			cout << f[a][b] << " ";
		}
		cout << endl; 
	}*/
	
	S = 201, T = 202;
	G[S].push_back(edge(1, -1)), G[101].push_back(edge(T, -2));
	for(int i = 1; i < 100; i++) G[i].push_back(edge(i+1, -1));
	for(int i = 200; i > 101; i--) G[i].push_back(edge(i-1, -2));
	for(int a = 0; a <= 100; a++){
		for(int b = 0; b <= 100; b++){
			int s = a, t = b+100;
			if(s == 0) s = S;
			if(t == 100) t = T;
			G[s].push_back(edge(t, f[a][b]));
		}
	}
	
	for(int x = 1; x <= A; x++){
		for(int y = 1; y <= B; y++){
			dijkstra(x, y);
			if(dist[T] != d[x][y]){
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}
	
	cout << "Possible" << endl;
	cout << 202 << " " << 200+101*101 << endl;
	for(int i = 1; i <= T; i++){
		for(int j = 0; j < G[i].size(); j++){
			cout << i << " " << G[i][j].to << " ";
			if(G[i][j].cost == -1) cout << "X" << endl;
			else if(G[i][j].cost == -2) cout << "Y" << endl;
			else cout << G[i][j].cost << endl;
		}
	}
	cout << S << " " << T << endl;
	return 0;
}