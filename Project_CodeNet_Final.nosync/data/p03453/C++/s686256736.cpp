#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000

#define Edge pair<long long,int>

vector<Edge> dijkstra(int s,vector<vector<Edge>> &E){
	int n = E.size();
	vector<Edge> dis(n);
	
	for(int i=0;i<n;i++){
		dis[i].first = Inf;
		dis[i].second = i;
	}
	
	dis[s].first=0;
	priority_queue<Edge,vector<Edge>,greater<Edge>> Q;
	Q.push(make_pair(0,s));
	vector<bool> visited(E.size(),false);
	while(Q.size()!=0){
		Edge e = Q.top();
		Q.pop();
		int now = e.second;
		if(visited[now])continue;
		visited[now] = true;
		
		
		for(int i=0;i<E[now].size();i++){
			long long cost = E[now][i].first;
			int to = E[now][i].second;
			if(dis[now].first + cost < dis[to].first){
				dis[to].first = dis[now].first+cost;
				Q.push(dis[to]);
			}
		}
	}
	
	return dis;
}
		


int main(){
	
	int N,M,S,T;
	cin>>N>>M>>S>>T;
	S--;T--;
	
	vector<vector<Edge>> E(N,vector<Edge> (0));
	
	
	for(int i=0;i<M;i++){
		long long a,b,c;
		cin>>a>>b>>c;
		a--;b--;
		c*=2;
		E[a].push_back(make_pair(c,b));
		E[b].push_back(make_pair(c,a));
	}
	
	vector<vector<Edge>> dis(2);
	vector<vector<Edge>> D;
	
	dis[0] = dijkstra(S,E);
	dis[1] = dijkstra(T,E);
	
	
	D = dis;
	
	long long d = dis[0][T].first;

	for(int i=0;i<2;i++)sort(dis[i].begin(),dis[i].end());
	
	vector<vector<int>> cnt(2,vector<int>(N,0));
	cnt[0][S]=1;cnt[1][T]=1;
	for(int i=0;i<2;i++){
		for(int j=0;j<N;j++){
			long long D1 = dis[i][j].first;
			int from = dis[i][j].second;
			
			for(int k=0;k<E[from].size();k++){
				long long D2 = E[from][k].first;
				int to = E[from][k].second;
				if(D1 + D2 + D[i^1][to].first==d){
					cnt[i][to] = mod(cnt[i][to] + cnt[i][from]);
				}
				
			}
		}
	}
	
	int ho = 0;
	for(int i=0;i<N;i++){
		if(D[0][i].first+D[1][i].first==d&&D[0][i].first==d/2){
			int x = mod(cnt[0][i] * cnt[1][i]);
			x = mod(x*x);
			ho = mod(x+ho);
		}
		
		for(int j=0;j<E[i].size();j++){
			int from = i;
			int to = E[i][j].second;
			long long DD = E[i][j].first;
			if(D[0][from].first+DD+D[1][to].first!=d)continue;
			if(D[0][from].first>=d/2||D[1][to].first>=d/2)continue;
			int x = mod(cnt[0][from]*cnt[1][to]);
			x = mod(x*x);
			ho = mod(x+ho);
		}
		
	}
	
	//cout<<ho<<endl;
	
	int ans = mod(cnt[0][T]*cnt[0][T]);
	
	ans = mod(ans - ho);
	

	
	
	cout<<ans<<endl;
	
	
	return 0;
}
