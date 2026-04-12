#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<int(n); i++)
using namespace std;

int N, deg[100000], cnt[100000], used[100000];
vector<int> G[100000];

int main(){
	cin >> N;
	rep(i, N-1){
		int a, b; cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
		deg[a]++; deg[b]++;
	}
	rep(i, N)rep(j, G[i].size()){
		if(deg[G[i][j]] == 1) cnt[i]++;
	}
	queue<int> que;
	rep(i, N){
		if(cnt[i] > 1){ cout << "First" << endl; return 0; }
		if(deg[i] == 1) que.push(i);
	}
	int size = N;
	while(size > 2){
		int a = que.front(); que.pop();
		if(used[a] == 1) continue;
		size -= 2;
		used[a] = 1;
		int to;
		rep(i, G[a].size()){
			if(used[G[a][i]] == 0) to = G[a][i];
		}
		used[to] = 1;
		rep(i, G[to].size()){
			if(used[G[to][i]] == 0){
				deg[G[to][i]]--;
				if(deg[G[to][i]] == 1){
					rep(j, G[G[to][i]].size()){
						if(used[G[G[to][i]][j]] == 0){
							cnt[G[G[to][i]][j]]++;
							if(cnt[G[G[to][i]][j]] > 1){ cout << "First" << endl; return 0; }
						}
					}
					que.push(G[to][i]);
				}
			}
		}
	}
	if(size == 2) cout << "Second" << endl;
	else cout << "First" << endl;
	return 0;
}
