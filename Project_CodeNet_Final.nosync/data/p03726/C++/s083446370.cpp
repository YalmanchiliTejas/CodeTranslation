#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;

vector<int> g[100100];
bool used[100100];

void dfs(int v,int p){
	for(int t:g[v]){
		if(p==t)continue;
		dfs(t,v);
	}
	if(used[v])return;
	if(p!=-1&&!used[p]){
		used[p]=1;
		used[v]=1;
		return;
	}
}

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for(int i=0;i<n-1;i++){
		int x,y; cin >> x >> y;
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(0,-1);
	for(int i=0;i<n;i++){
		if(!used[i]){
			cout << "First" << endl;
			return 0;
		}
	}
	cout << "Second" << endl;
}