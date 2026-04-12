#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pi;

const ll mod = 1000000007;

ll distS[100005], distE[100005], waysS[100005], waysE[100005];
vector<pi> AdjList[100005];
ll N, M, S, T;
ll U, V, D;
vector<pair<pi,ll> > edges;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	cin >> S >> T;
	for (int i = 1; i <= M; ++i){
		cin >> U >> V >> D;
		AdjList[U].push_back(pi(V,D));
		AdjList[V].push_back(pi(U,D));
		edges.push_back(make_pair(pi(U,V),D));
		//edges.push_back(make_pair(pi(V,U),D));
	}
	for (int i = 1; i <= N; ++i){
		distS[i] = distE[i] = 1e17;
		waysS[i] = waysE[i] = 0;
	}
	distS[S] = 0;
	distE[T] = 0;
	waysS[S] = 1;
	waysE[T] = 1;
	
	priority_queue<pi,vector<pi>,greater<pi> > pq;
	pq.push(pi(0,S));
	while (!pq.empty()){
		pi C = pq.top();
		pq.pop();
		if (C.first != distS[C.second]) continue;
		for (auto it : AdjList[C.second]){
			if (distS[it.first] > C.first + it.second){
				distS[it.first] = C.first + it.second;
				waysS[it.first] = waysS[C.second];
				pq.push(pi(distS[it.first],it.first));
			}
			else if (distS[it.first] == C.first + it.second){
				waysS[it.first] += waysS[C.second];
				waysS[it.first] %= mod;
			}
		}
	}


	pq.push(pi(0,T));
	while (!pq.empty()){
		pi C = pq.top();
		pq.pop();
		if (C.first != distE[C.second]) continue;
		for (auto it : AdjList[C.second]){
			if (distE[it.first] > C.first + it.second){
				distE[it.first] = C.first + it.second;
				waysE[it.first] = waysE[C.second];
				pq.push(pi(distE[it.first],it.first));
			}
			else if (distE[it.first] == C.first + it.second){
				waysE[it.first] += waysE[C.second];
				waysE[it.first] %= mod;
			}
		}
	}
	ll sdist = distS[T], w = (waysS[T]*waysE[S])%mod;
	//cout << w << '\n';
	for (int i = 1; i <= N; ++i){
		if (2*distS[i] == sdist && 2*distE[i] == sdist){
			w -= ((((waysS[i]*waysS[i])%mod)*((waysE[i]*waysE[i])%mod))%mod);
			w %= mod;
			w += mod;
			w %= mod;
		}
	}
	for (int i = 0; i < edges.size(); ++i){
		if (2*distS[edges[i].first.first] >= sdist){
			swap(edges[i].first.first,edges[i].first.second);
		}
		if (distS[edges[i].first.first]+distE[edges[i].first.second]+edges[i].second == sdist && 2*distS[edges[i].first.first] < sdist && 2*distE[edges[i].first.second] < sdist){
			w -= ((((waysS[edges[i].first.first]*waysS[edges[i].first.first])%mod)*((waysE[edges[i].first.second]*waysE[edges[i].first.second])%mod))%mod);
			w %= mod;
			w += mod;
			w %= mod;
		}
	}
	cout << w << '\n';
	cout << flush;
	//for (int i = 0; i < 1e9; ++i){for (int j = 0; j < 1e9; ++j){}}
}