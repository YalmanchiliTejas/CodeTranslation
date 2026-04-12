#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N,M,S,T;
vector<pair<int, int> > G[100100];

const long long mod = 1000000007;

pair<vector<long long>, vector<long long> > dist(int s)
{
	vector<long long> dist(N,1e18);
	priority_queue<pair<long long, int> > Q;
	Q.push({0,s}); dist[s] = 0;
	while (!Q.empty()){
		int x = Q.top().second; long long c = -Q.top().first; Q.pop();
		if (dist[x] < c) continue;
		for (auto &p : G[x]){
			int y = p.first;
			long long nc = p.second + c;
			if (dist[y] > nc){
				Q.push({-nc,y});
				dist[y] = nc;
			}
		}
	}

	vector<long long> cnt(N);
	cnt[s] = 1;
	vector<pair<long long, int> > st;
	for (int i=0;i<N;i++) st.push_back({dist[i],i});
	sort(st.begin(),st.end());
	for (auto &p : st){
		int x = p.second;
		for (auto &p : G[x]){
			int y = p.first, c = p.second;
			if (dist[y] == dist[x] + c) cnt[y] = (cnt[y] + cnt[x]) % mod;
		}
	}
	return {dist, cnt};
}

int main()
{
	scanf ("%d %d %d %d",&N,&M,&S,&T); S--; T--;
	for (int i=0;i<M;i++){
		int x,y,c; scanf ("%d %d %d",&x,&y,&c); x--; y--;
		G[x].push_back({y,c});
		G[y].push_back({x,c});
	}

	auto p = dist(S);
	auto q = dist(T);

	long long u = p.first[T];
	long long ans = p.second[T]; ans = ans * ans % mod;
	if (u % 2 == 0) for (int i=0;i<N;i++){
		if (p.first[i] == u / 2 && q.first[i] == u / 2){
			long long now = p.second[i] * q.second[i] % mod;
			ans = (ans + mod - now * now % mod) % mod;
		}
	}

	vector<bool> can(N);
	for (int i=0;i<N;i++) if (p.first[i] + q.first[i] == u) can[i] = 1;
	for (int i=0;i<N;i++) if (can[i] && p.first[i] < u/2){
		for (auto &e : G[i]){
			int j = e.first;
			if (can[j] && q.first[j] < u/2 && p.first[i] + e.second + q.first[j] == u){
				long long now = p.second[i] * q.second[j] % mod;
				ans = (ans + mod - now * now % mod) % mod;
			}
		}
	}
	printf ("%lld\n",ans);


	return 0;
}