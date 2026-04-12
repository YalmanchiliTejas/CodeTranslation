#include <iostream>
#include <vector>
using namespace std;
bool visited[9];
int N,M,k;
vector<int> G[9];
int dfs(int s){
	int res = 0;
	visited[s] = true;
	++k;
	for(auto& nb:G[s]){
		if(!visited[nb]) {
			res += dfs(nb);
		}
	}
	if(k == N) res = 1;
	visited[s] = false;
	--k;
	return res;
}
int main(){
	cin >> N >> M;
	int a,b;
	while(M--){
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	cout << dfs(1) << endl;
}