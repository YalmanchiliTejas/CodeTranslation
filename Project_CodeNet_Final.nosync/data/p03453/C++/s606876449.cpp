#include<bits/stdc++.h>
#define MAXN 100010
#define P 1000000007LL
#define ii pair<int, int>
#define ll long long
#define ff first
#define ss second
using namespace std;

vector<ii> gr[MAXN];
int N, M;

void shortest_path(int S, vector<ll> &dist, vector<ll> &poss){
	dist = vector<ll> (N+1, (1LL << 60));
	poss = vector<ll> (N+1, 0);

	priority_queue<pair<ll, int> > pq;
	pq.push({0, S});
	dist[S] = 0;
	ll d;
	int u;
	vector<int> elem;
	while(!pq.empty()){
		tie(d, u) = pq.top();
		pq.pop();
		d *= -1;

		if(d != dist[u]) continue;
		elem.push_back(u);

		for(auto &v : gr[u]){
			if(dist[v.ff] > dist[u] + v.ss){
				dist[v.ff] = dist[u] + v.ss;
				pq.push({-dist[v.ff], v.ff});
			}
		}
	}
	poss[S] = 1;
	for(auto &u : elem){
		for(auto &v : gr[u]){
			if(dist[v.ff] + v.ss == dist[u]){
				poss[u] += poss[v.ff];
				if(poss[u] >= P)
					poss[u] -= P;
			}
		}
	}

}

vector<ll> distS, possS, distT, possT; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int S, T;
	int a, b, c;
	
	cin >> N >> M >> S >> T;

	for(int i = 0; i < M; i++){
		cin >> a >> b >> c;
		gr[a].push_back({b, c});
		gr[b].push_back({a, c});
	}

	shortest_path(S, distS, possS);
	shortest_path(T, distT, possT);

	ll ans = 0LL;
	for(int i = 1; i <= N; i++){
		if(distS[i] + distT[i] != distS[T]) continue;
		if(distS[i] == distT[i]) ans += ((possS[i] * possS[i]) %P ) * ((possT[i] * possT[i]) % P), ans %= P;

		for(auto &u : gr[i]){
			if(distS[u.ff] + u.ss != distS[i] || distT[i] + u.ss != distT[u.ff]) continue;

 			if(distT[i] < distS[i] && distS[u.ff] < distT[u.ff]){
 				/*
 				cout << i << " " << u.ff << " : " << distS[i] << " " << distT[u.ff] << " " << u.ss << endl;
 				cout << possS[i] << " " << possT[u.ff] << "\n"; */
				ans += ((possS[u.ff] * possS[u.ff]) %P ) * ((possT[i] * possT[i]) % P), ans %= P;
 			}
		}
	}
	ans = possS[T] * possT[S] - ans;
	ans %= P;
	ans += P;
	ans %= P;

	cout << ans << "\n";
	return 0;
}