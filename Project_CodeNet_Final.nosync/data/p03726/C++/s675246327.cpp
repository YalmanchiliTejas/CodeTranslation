#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool used[100000] = {};
vector<int> G[100000];

int nxt(int v){
	for(int to : G[v]){
		if(!used[to]) return to;
	}
	return -1;
}

int main(){
	int n,d[100000] = {};
	bool flag = false;
	cin >> n;
	for(int i = 0;i < n - 1;i++){
		int a,b;
		cin >> a >> b; a--;b--;
		G[a].push_back(b);
		G[b].push_back(a);
		d[a]++;
		d[b]++;
	}
	queue<int> que;
	for(int i = 0;i < n;i++){
		if(d[i] == 1) que.push(i);
	}
	while(!que.empty()){
		int v = que.front(),nextv = nxt(v);que.pop();
		if(used[v]) continue;
		if(nextv == -1){
			flag = true;
			break;
		}
		used[v] = true;
		used[nextv] = true;
		for(int to : G[nextv]){
			if(!used[to]){
				d[to]--;
				if(d[to] == 1) que.push(to);
			}
		}
	}
	for(int i = 0;i < n;i++) if(!used[i]) flag = true;
	if(flag) cout << "First" << endl;
	else cout << "Second" << endl;
	return 0;
}