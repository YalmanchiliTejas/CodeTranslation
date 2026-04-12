#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct Edge{
	int v;
	long long d;
};

struct Data{
	long long time;
	int u, v;
	int from;
};

bool operator>(const Data& a, const Data& b){
	return a.time > b.time;
}


const long long mod = 1E9+7;
const long long inf = 1E15;

int n, m;
int s, t;


vector<Edge> edges[100000];
long long dist[100000][2];
long long pattern[100000][2] = {0};


int main(){
	Edge e;

	cin>>n>>m;
	cin>>s>>t;
	s--;
	t--;

	for(int i=0;i<m;i++){
		int a,b,d;
		cin>>a>>b>>d;
		e.d = d;
		e.v = b-1;
		edges[a-1].push_back(e);
		e.v = a-1;
		edges[b-1].push_back(e);
	}

	for(int i=0; i<n; i++){
		dist[i][0] = dist[i][1] = inf;
	}

	priority_queue<Data,vector<Data>,greater<Data> > pq;
	Data data;

	dist[s][0] = 0;
	dist[t][1] = 0;
	pattern[s][0] = 1;
	pattern[t][1] = 1;
	for(int i=0; i<edges[s].size(); i++){
		data.time = edges[s][i].d;
		data.u = s;
		data.v = edges[s][i].v;
		data.from = 0;
		pq.push(data);
	}
	for(int i=0; i<edges[t].size(); i++){
		data.time = edges[t][i].d;
		data.u = t;
		data.v = edges[t][i].v;
		data.from = 1;
		pq.push(data);
	}


	while(!pq.empty()){
		data = pq.top();
		pq.pop();
		int from = data.from;
		int u = data.u;
		int v = data.v;
		long long t = data.time;

		if(t == dist[v][from]){
			pattern[v][from] += pattern[u][from];
			pattern[v][from] %= mod;
		}
		else if(t < dist[v][from]){
			pattern[v][from] = pattern[u][from];
			dist[v][from] = t;

			auto es = edges[v];
			for(int i=0; i<es.size(); i++){
				if(pattern[es[i].v][from] == 0){
					data.time = dist[v][from] + es[i].d;
					data.u = v;
					data.v = es[i].v;
					data.from = from;
					pq.push(data);
				}
			}
		}
	}

	long long min_time = dist[s][1];
	long long res = 0;
	long long routes = 0;
	//cout <<"min_time"<<min_time<<endl;

	for(int u=0; u<n; u++){
		//cout<<u<<" "<<dist[u][0]<<" "<<pattern[u][0]<<" "<<dist[u][1]<<" "<<pattern[u][1]<<endl;
		if(dist[u][0] == dist[u][1] && dist[u][0]*2 == min_time){
			long long buf = pattern[u][0] * pattern[u][1] % mod;
			res += routes * buf;
			res %= mod;
			routes += buf;
			routes %= mod;
			//cout <<"node"<<u<<":"<< res <<" "<<routes<<endl;
		}
		for(int i=0; i<edges[u].size(); i++){
			int v = edges[u][i].v;
			int d = edges[u][i].d;

			if(dist[u][0] + dist[v][1] + d == min_time &&
					dist[u][0] * 2 < min_time &&
					dist[v][1] * 2 < min_time){

				long long buf = pattern[u][0] * pattern[v][1] % mod;
				res += routes * buf;
				res %= mod;
				routes += buf;
				routes %= mod;
				//cout <<"edge"<<u<<" "<<v<<":"<< res <<" "<<routes<<endl;
			}
		
		}

	}


	cout << res * 2 % mod << endl;

	return 0;
}

