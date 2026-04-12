#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const long long INF = 1LL << 60;
const long long MOD = 1000000007;

vector<long long> dijkstra(const vector<vector<pair<int,int>>>& g, int S){
	int n = g.size();
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> qu;
	qu.emplace(0, S);
	vector<long long> res(n, INF);
	res[S] = 0;
	while(!qu.empty()){
		auto p = qu.top(); qu.pop();
		const int pos = p.second;
		const long long dist = p.first;
		for(const auto& next : g[pos]){
			int nextPos = next.first;
			long long nextDist = res[pos] + next.second;
			if(nextDist < res[nextPos]){
				res[nextPos] = nextDist;
				qu.emplace(nextDist, nextPos);
			}
		}
	}
	return res;
}

vector<long long> calcPath(const vector<vector<pair<int,int>>>& g, const vector<long long>& dist, int S){
	vector<long long> res(g.size(), 0);
	vector<int> visit(g.size(), 0);
	res[S] = 1;
	priority_queue<pair<long long, int>> qu;
	qu.emplace(dist[S], S);
	while(!qu.empty()){
		auto p = qu.top(); qu.pop();
		int pos = p.second;
		if(visit[pos]) continue;
		visit[pos] = 1;
		for(auto& next : g[pos]){
			if(dist[next.first] + next.second == dist[pos]){
				res[next.first] = (res[next.first] + res[pos]) % MOD;
				qu.emplace(dist[next.first], next.first);
			}
		}
	}
	return res;
}

int main(){
	int N, M;
	while(cin >> N >> M){
		int S, T; cin >> S >> T;
		--S; --T;
		vector<vector<pair<int,int>>> g(N);
		for(int i=0;i<M;i++){
			int U, V, D; cin >> U >> V >> D;
			--U; --V;
			g[U].emplace_back(V, D);
			g[V].emplace_back(U, D);
		}
		vector<long long> distS = dijkstra(g, S);
		vector<long long> distT = dijkstra(g, T);
		vector<long long> pathNumS = calcPath(g, distT, S);
		vector<long long> pathNumT = calcPath(g, distS, T);
		long long res = pathNumS[T] * pathNumS[T] % MOD;
		for(int i=0;i<N;i++){
			if(distS[T]%2 == 0 && distS[i] == distS[T]/2){
				long long num = pathNumS[i] * pathNumT[i] % MOD;
				long long sub = num * num % MOD;
				res = (res + MOD - sub) % MOD;
			}
			if(2*distS[i] < distS[T]){
				for(const auto& p : g[i]){
					if(distS[i] + p.second == distS[p.first] && distS[T] < 2*distS[p.first]){
						long long num = pathNumS[i] * pathNumT[p.first] % MOD;
						long long sub = num * num % MOD;
						res = (res + MOD - sub) % MOD;
					}
				}
			}
		}
		cout << res << endl;
	}
}
