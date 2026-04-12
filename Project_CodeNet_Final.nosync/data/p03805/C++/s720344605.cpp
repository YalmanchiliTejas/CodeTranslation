#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<tuple>
#include<iomanip>
#define int long 
using namespace std;

int N,M;
vector<int> graph[10];

int answer = 0;
bool visited[10];
void dfs(int v,int cnt) {
	visited[v] = true;
	cnt++;
	if(cnt == N) {
		answer++;
    }
	for(int u:graph[v]) {
		if(!visited[u]) {
			dfs(u,cnt);
		}
	}
	visited[v] = false;
}

signed main() {
	cin >> N >> M;
	for(int i = 0;i < M;i++) {
		int A,B;
		cin >> A >> B;
		graph[A - 1].push_back(B - 1);
		graph[B - 1].push_back(A - 1);
    }
	dfs(0,0);
	cout << answer << endl;
}